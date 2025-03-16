#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <time.h>
#include <sys/time.h>

#define SIZE 50000

int arr[SIZE];

int QuickSort(int arr[], int low, int high) 
{
    int key = arr[high];
    int i = low - 1;
    for (int j = low; j < high; j++) 
    {
        if (arr[j] < key)
        {
            i++;
            int temp = arr[i];
            arr[i] = arr[j];
            arr[j] = temp;
        }
    }
    int temp = arr[i + 1];
    arr[i + 1] = arr[high];
    arr[high] = temp;
    return i + 1;
}

// Quick Sort function
void quickSort(int arr[], int low, int high) 
{
    if (low < high) 
    {
        int pi = QuickSort(arr, low, high);
        quickSort(arr, low, pi - 1);
        quickSort(arr, pi + 1, high);
    }
}

// Insertion Sort function
void insertionSort(int arr[], int start, int end) 
{
    for (int i = start + 1; i <= end; i++) 
    {
        int key = arr[i];
        int j = i - 1;
        while (j >= start && arr[j] > key) 
        {
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j + 1] = key;
    }
}

// Thread function for Quick Sort
void* quickSortThread(void* arg) 
{
    clock_t t; 
    t = clock(); 
    quickSort(arr, 0, SIZE / 2 - 1);
    t = clock() - t; 
    double time_taken = ((double)t)/CLOCKS_PER_SEC;    
    printf("Quick Sort took %.2f ms\n", time_taken);
    return NULL;
}

// Thread function for Insertion Sort
void* insertionSortThread(void* arg)
{
    clock_t t; 
    t = clock(); 
    insertionSort(arr, SIZE / 2, SIZE - 1);
    t = clock() - t; 
    double time_taken = ((double)t)/CLOCKS_PER_SEC;    
    printf("Insertion Sort took %.2f ms\n", time_taken);
    return NULL;
}

int main()
{
    srand(time(0));

    for (int i = 0; i < SIZE; i++)
    {
        arr[i] = rand() % 100000;
    }

    pthread_t thread1, thread2;

    pthread_create(&thread1, NULL, quickSortThread, NULL);
    pthread_create(&thread2, NULL, insertionSortThread, NULL);
    
    pthread_join(thread1, NULL);
    pthread_join(thread2, NULL);

    FILE* file1 = fopen("firstHalf.txt", "w");

    for (int i = 0; i < SIZE / 2; i++) 
        fprintf(file1, "%d ", arr[i]);

    fclose(file1);

    FILE* file2 = fopen("secondHalf.txt", "w");

    for (int i = SIZE / 2; i < SIZE; i++) 
        fprintf(file2, "%d ", arr[i]);

    fclose(file2);
    
    return 0;
}

