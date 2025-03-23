#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <time.h>
#include <sys/time.h>

#define MAXTHREADS 128

int n;
int **A, **B, **C;

void initialize_matrix(int **matrix) 
{
    for (int i = 0; i < n; i++) 
    {
        for (int j = 0; j < n; j++) 
        {
            matrix[i][j] = (int)(rand() % 100)+ 1;
        }
    }
}

void save_matrix(const char *filename, int **matrix) 
{
    FILE *file = fopen(filename, "w");

    for (int i = 0; i < n; i++) 
    {
        for (int j = 0; j < n; j++) 
        {
            fprintf(file, "%d ", matrix[i][j]);
        }
        fprintf(file, "\n");
    }

    fclose(file);
}

void *multiply_rows(void *arg)
{
    int *params = (int *)arg;
    int thread_id = params[0];
    int num_threads = params[1];  // Now receiving the actual number of threads
    
    int rows_per_thread = n / num_threads;

    int remainder = n % num_threads;
    int start = thread_id * rows_per_thread;

    if (thread_id < remainder) 
    {
        start += thread_id;
        rows_per_thread++;
    } 
    else 
        start += remainder;
    
    int end = start + rows_per_thread;
    
    for (int i = start; i < end; i++) 
    {
        for (int j = 0; j < n; j++) 
        {
            C[i][j] = 0;
            for (int k = 0; k < n; k++) 
            {
                C[i][j] += A[i][k] * B[k][j];
            }
        }
    }
    return NULL;
}


int main(int argc, char *argv[]) 
{
    if (argc != 2) {
        printf("Enter matrix size as argument.\n");
        return 1;
    }
    
    n = atoi(argv[1]);
    if (n < 128) 
    {
        printf("Matrix size must be at least 128.\n");
        return 1;
    }

    srand(time(NULL));
    A = malloc(n * sizeof(int *));
    B = malloc(n * sizeof(int *));
    C = malloc(n * sizeof(int *));

    for (int i = 0; i < n; i++) 
    {
        A[i] = malloc(n * sizeof(int));
        B[i] = malloc(n * sizeof(int));
        C[i] = malloc(n * sizeof(int));
    }
    
    initialize_matrix(A);
    initialize_matrix(B);
    save_matrix("A.txt", A);
    save_matrix("B.txt", B);

for (int count = 1; count <= MAXTHREADS; count++) 
{
    pthread_t threads[MAXTHREADS];
    int threadParams[MAXTHREADS][2]; // Thread ID and total number of threads
    clock_t t;
    t = clock();
    
    for (int i = 0; i < count; i++) 
    {
        threadParams[i][0] = i;        // Thread ID
        threadParams[i][1] = count;    // Total number of threads
        pthread_create(&threads[i], NULL, multiply_rows, &threadParams[i]);
    }

    t = clock() - t;
    double time_taken = ((double)t)/CLOCKS_PER_SEC;
    printf("(%d, %d, %.6f)%s", n, count, time_taken, (count == MAXTHREADS) ? "]\n" : ", ");
   
  //  printf("%d- (%.6f sec)", count, time_taken);
    printf("\n");
}
    
    save_matrix("C.txt", C);

    for (int i = 0; i < n; i++) 
    {
        free(A[i]);
        free(B[i]);
        free(C[i]);
    }
    free(A);
    free(B);
    free(C);
    return 0;
}

/*
Do you observe diminishing returns as we increase the number of threads?
Yes, due to factors like memory bandwidth limitations, CPU cache contention, and thread synchronization overhead,
there comes a point where adding more threads does not yield a proportional speedup. Instead, performance gains diminish.
*/