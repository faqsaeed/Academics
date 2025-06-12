#include<iostream>
using namespace std;
class Heap
{
	int* h_Arr, size, cap;
public:
	Heap(int arr[], int s)
	{
		size = s;
		cap = s;
		h_Arr = new int[size];
		for (int i = 0; i < size; i++)
			h_Arr[i] = arr[i];
    }

	void buildheap()
	{
		for (int i = (size - 2) / 2; i >= 0; i--)
		{
			heapify(i);
		}
	}
	void heapify(int index)
	{
		int largest = index;
		int left = 2 * index + 1;
		int right = 2 * index + 2;

		if (left < size && h_Arr[left] > h_Arr[largest])
			largest = left;
		if (right < size && h_Arr[right] > h_Arr[largest])
			largest = right;
		if (largest != index)
		{
			swap(h_Arr[largest], h_Arr[index]);
			heapify(largest);
		}
	}
	int extMax()
	{
		swap(h_Arr[size-1],h_Arr[0]);
		size--;
		heapify(0);
		return h_Arr[size+1];
	}
	void print()
	{
		for (int i = 0; i < size; i++)
			cout << h_Arr[i] << " ";
		cout << endl;
	}
	void heapSort()
	{
		int temp = size;
		for (int i = size-1; i>=0; i--)
		{
			swap(h_Arr[0], h_Arr[i]);
			size--;
			heapify(0);
		}
		size = temp;
	}
};
int main()
{
	int arr[] = { 25,20,22,17,15,14,18,8,10,7,5,12,6,9,2 };
	//make a complete binary tree
	Heap h1(arr, sizeof(arr) / 4);
	h1.print();
	h1.buildheap();
	h1.print();// print the max heap
/*use max heap for sorting. remove max elements one by one from the heap
and place them at the last.*/
	h1.heapSort();
	h1.print(); //print the sorted array
}