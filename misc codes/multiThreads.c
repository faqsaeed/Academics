#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <time.h>
#include <unistd.h>

typedef struct {
    int student_num;
} ThreadData;

void* grade_student(void* arg) {
    ThreadData* data = (ThreadData*) arg;
    int score = rand() % 51 + 50; // random score between 50 and 100
    char grade;

    if (score >= 90) grade = 'A';
    else if (score >= 80) grade = 'B';
    else if (score >= 70) grade = 'C';
    else if (score >= 60) grade = 'D';
    else grade = 'F';

    printf("Thread ID: %lu, Student %d, Score: %d, Grade: %c\n",
           pthread_self(), data->student_num, score, grade);

    free(arg);
    return NULL;
}

int main(int argc, char* argv[]) {
    if (argc != 2) {
        printf("Usage: %s <number of students>\n", argv[0]);
        return 1;
    }

    int N = atoi(argv[1]);
    pthread_t threads[N];
    srand(time(NULL));

    for (int i = 0; i < N; ++i) {
        ThreadData* data = malloc(sizeof(ThreadData));
        data->student_num = i + 1;
        pthread_create(&threads[i], NULL, grade_student, data);
    }

    for (int i = 0; i < N; ++i) {
        pthread_join(threads[i], NULL);
    }

    printf("Grading Completed!\n");
    return 0;
}

