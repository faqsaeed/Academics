#include <iostream>
#include <queue>
#include <vector>
#include <string>
#include <cstdlib>
using namespace std;

struct Node {
    char ch;
    int freq;
    Node *left, *right;

    Node(char c, int f) : ch(c), freq(f), left(nullptr), right(nullptr) {}
};

struct Compare {
    bool operator()(Node* a, Node* b) 
    {
        return a->freq > b->freq;
    }
};

vector<pair<char, int>> calculateFrequency(const string& input) 
{
    vector<pair<char, int>> freqVec;
    vector<int> freq(256, 0); //256 cells initialised to 0

    for (char ch : input) 
    {
        freq[ch]++;// ch = ascii value of the character, incrementing it
    }

    for (int i = 0; i < 256; i++) 
    {
        if (freq[i] > 0) 
            freqVec.push_back({char(i), freq[i]});
        
    }

    return freqVec;
}

Node* buildHuffmanTree(const vector<pair<char, int>>& freqVec) 
{
    priority_queue<Node*, vector<Node*>, Compare> minQ;

    for (const auto& pair : freqVec) 
    {
        minQ.push(new Node(pair.first, pair.second));
    }

    while (minQ.size() > 1) 
    {
        Node* left = minQ.top(); 
        minQ.pop();
        Node* right = minQ.top(); 
        minQ.pop();

        Node* newNode = new Node('\0', left->freq + right->freq);
        newNode->left = left;
        newNode->right = right;

        minQ.push(newNode);
    }

    return minQ.top();
}

void generateCodes(Node* root, string code, vector<pair<char, string>>& huffmanCodes) 
{
    if (!root) 
        return;

    if (root->ch != '\0') 
        huffmanCodes.push_back({root->ch, code});
    

    generateCodes(root->left, code + "0", huffmanCodes);
    generateCodes(root->right, code + "1", huffmanCodes);
}

string encode(const string& input, const vector<pair<char, string>>& huffmanCodes) 
{
    string encodedString;

    for (char ch : input) 
    {
        for (const auto& pair : huffmanCodes) 
        {
            if (pair.first == ch) 
            {
                encodedString += pair.second;
                break;
            }
        }
    }
    return encodedString;
}

string decode(const string& encoded, Node* root) 
{
    string decodedString;
    Node* current = root;

    for (char bit : encoded) 
    {
        if (bit == '0') 
            current = current->left;
        else 
            current = current->right;
        

        if (current->left == nullptr && current->right == nullptr) 
        {
            decodedString += current->ch;
            current = root;
        }
    }

    return decodedString;
}

void displayResults(const string& input, const string& encoded, const string& decoded, const vector<pair<char, string>>& huffmanCodes) 
{
    system("clear");
    cout << "Original string: " << input << endl;
    cout << "Original size: " << input.size() << " bytes" << endl;
    cout << "Encoded string: " << encoded << endl;
    cout << "Encoded size: " << encoded.size() / 8 << " bytes" << endl;

    cout << "Huffman Codes:" << endl;
    for (const auto& pair : huffmanCodes) 
    {
        cout << pair.first << ": " << pair.second << endl;
    }

    cout << "Decoded string: " << decoded << endl;
}

int main() {
    string input;
    cout << "Enter a string: ";
    getline(cin, input);

    vector<pair<char, int>> freqVec = calculateFrequency(input);

    Node* root = buildHuffmanTree(freqVec);

    vector<pair<char, string>> huffmanCodes;
    generateCodes(root, "", huffmanCodes);

    string encoded = encode(input, huffmanCodes);

    string decoded = decode(encoded, root);

    displayResults(input, encoded, decoded, huffmanCodes);

    return 0;
}
