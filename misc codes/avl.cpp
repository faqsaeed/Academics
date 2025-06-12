#include <iostream>
#include <vector>
#include <optional> // For std::optional
using namespace std;

class HashTable {
private:
    vector<optional<int>> table; // Use optional to distinguish empty and deleted slots
    int capacity;
    int size;

    // Hash function
    int hash(int key) const {
        return key % capacity;
    }

    // Quadratic probing
    int quadraticProbe(int key, int i) const {
        return (hash(key) + i * i) % capacity;
    }

    // Resize the table
    void resize() {
        int oldCapacity = capacity;
        capacity *= 2;
        vector<optional<int>> oldTable = table;

        table.clear();
        table.resize(capacity, nullopt);
        size = 0;

        for (const auto& slot : oldTable) {
            if (slot.has_value()) {
                insert(slot.value());
            }
        }
    }

public:
    // Constructor
    HashTable(int initCapacity = 10) : capacity(initCapacity), size(0) {
        table.resize(capacity, nullopt);
    }

    // Insert
    void insert(int key) {
        if (size >= capacity / 2) {
            resize();
        }

        int i = 0, idx = hash(key);
        while (table[idx].has_value()) 
        {
            if (table[idx].value() == key) {
                return; // Key already exists
            }
            i++;
            idx = quadraticProbe(key, i);
        }

        table[idx] = key;
        size++;
    }

    // Search
    bool search(int key) const {
        int i = 0, idx = hash(key);
        while (table[idx].has_value() || table[idx] == nullopt) 
        {
            if (table[idx] && table[idx].value() == key) {
                return true;
            }
            i++;
            idx = quadraticProbe(key, i);
            if (i > capacity) 
                break; // Prevent infinite loop
        }
        return false;
    }

    // Remove
    bool remove(int key) {
        int i = 0, idx = hash(key);
        while (table[idx].has_value() || table[idx] == nullopt) 
        {
            if (table[idx] && table[idx].value() == key) 
            {
                table[idx] = nullopt; // Mark slot as empty
                size--;
                return true;
            }
            i++;
            idx = quadraticProbe(key, i);
            if (i > capacity) 
                break; // Prevent infinite loop
        }
        return false;
    }

    // Display
    void display() const {
        cout << "Hash Table: ";
        for (const auto& slot : table) {
            if (!slot.has_value()) {
                cout << "[ ] ";
            } else {
                cout << "[" << slot.value() << "] ";
            }
        }
        cout << endl;
    }

    // Get size
    int getSize() const {
        return size;
    }
};

int main() {
    HashTable ht(19);

    // Insert elements
    ht.insert(5);
    ht.insert(10);
    ht.insert(15);
    ht.insert(20);
    ht.insert(25);
    ht.insert(30);

    ht.display();

    // Search elements
    cout << "Searching for 15: " << (ht.search(15) ? "Found" : "Not Found") << endl;
    cout << "Searching for 100: " << (ht.search(100) ? "Found" : "Not Found") << endl;

    // Remove element
    ht.remove(20);
    ht.display();

    return 0;
}
