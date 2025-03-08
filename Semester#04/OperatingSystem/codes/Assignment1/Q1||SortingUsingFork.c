#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

#define SIZE 10

void sort(int arr[], int pos)
{
	for (int i = 1; i < pos; ++i) 
	{
        	int key = arr[i];
        	int j = i - 1;

        	while (j >= 0 && arr[j] > key) 
		{
            		arr[j + 1] = arr[j];
            		j = j - 1;
        	}
        	arr[j + 1] = key;
    	}	
}

void print(const int arr[], const int n)
{
	for(int i = 0; i < n; i++)
	{
		printf("%d ", arr[i]);
	}
	printf("\n");
}

int main(int agrc, char*agrv[])
{
	if(agrc != SIZE + 1)
	{
		printf("Not Enough Variables Passed\n");
		return(-1);
	}

	int arr[SIZE];
	for(int i = 0; i < SIZE; i++)
	{
		arr[i] = atoi(agrv[i +1]);
	}
	
	int position = 0;
	for(int i = 0; i < SIZE; i++)
	{
		pid_t pid = fork();
		if(pid < 0)
		{
			printf("\nFork Failed!!\n");
			return(-1);
		}
		if(pid == 0)
		{
			position = i + 1;
		}
		else
		{
			wait(NULL);
			break;
		}
	}
	sort(arr, position);

	printf("Process: %d Parent ID: %d Process ID: %d \n", position, getppid(), getpid());
	print(arr, position);

	return 0;
}
