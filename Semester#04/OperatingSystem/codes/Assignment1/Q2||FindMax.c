#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

void readFromFile(FILE* file, int* arr)
{
    int i = 0;
    while (fscanf(file, "%d", &arr[i]) != EOF)
    {
        i++;
    }
}

int findMax(int* arr, int start, int end) 
{
    if (end - start <= 2) 
    {
        int maxVal = arr[start];
        if (end - start > 1 && arr[start + 1] > maxVal)
        {
            maxVal = arr[start + 1];
        }
        return maxVal; // Return instead of exit
    }

    int mid = (start + end) / 2;
    pid_t leftChild, rightChild;
    int status1, status2;

    leftChild = fork();
    if (leftChild < 0)
    {
        printf("\nFork failed\n");
        exit(1);
    }
    if (leftChild == 0)
    {
        int leftMax = findMax(arr, start, mid);
        exit(leftMax); 
    }

    rightChild = fork();
    if (rightChild < 0)
    {
        printf("\nFork failed\n");
        exit(1);
    }
    if (rightChild == 0)
    {
        int rightMax = findMax(arr, mid, end);
        exit(rightMax); 
    }

    waitpid(leftChild, &status1, 0);
    waitpid(rightChild, &status2, 0);

    int leftMax = WEXITSTATUS(status1);
    int rightMax = WEXITSTATUS(status2);

    return (leftMax > rightMax ? leftMax : rightMax); // Return instead of exit
}

int main(int argc, char* argv[])
{
    if(argc < 2)
    {
        printf("Pass a Number!!!\n");
        return(-1);
    }

    pid_t pid1;
    pid1 = fork();
    if(pid1 < 0)
    {
        printf("\nFork Failed!!\n");
        return(-1);
    }
    if(pid1 == 0)
    {
        execlp("gcc", "gcc", "q2helper.c", "-o", "createFile", NULL);
        perror("execlp gcc failed");
        exit(1);
    }
    else
    {
        wait(NULL);
        pid1 = fork();
        if(pid1 < 0)
        {
            printf("\nFork Failed!!\n");
            return(-1);
        }
        if(pid1 == 0)
        {
            execlp("./createFile", "./createFile", argv[1], NULL);
            perror("execlp ./createFile failed");
            exit(1);
        }
        else
        {
            wait(NULL);
        }
    }

    int n = atoi(argv[1]);
    int *arr = (int*)malloc(n * sizeof(int));

    FILE* file = fopen("input.txt", "r"); 
    if (file == NULL)
    {
        printf("Error opening file!\n");
        free(arr);
        return -1;
    }

    readFromFile(file, arr);
    fclose(file);

    int maxNumber = findMax(arr, 0, n);
    printf("Maximum Number in the file is: %d\n", maxNumber);

    free(arr);
    return 0;
}
