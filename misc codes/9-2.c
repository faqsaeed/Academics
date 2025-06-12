#include <stdio.h>
#include <pthread.h>
#include <semaphore.h>
#include <stdlib.h>
#include <unistd.h>

sem_t mutex, turnstile, professorBlock;
int studentCount = 0;

void *student(void *arg)
{
    int id = *(int *)arg;
    sem_wait(&turnstile);
    sem_wait(&mutex);
    studentCount++;
    printf("Student %d ENTERED. Total: %d\n", id, studentCount);
    sem_post(&mutex);
    sem_post(&turnstile);

    sleep(rand() % 3 + 1);

    sem_wait(&mutex);
    studentCount--;
    printf("Student %d LEFT. Total: %d\n", id, studentCount);
    sem_post(&mutex);

    pthread_exit(NULL);
}

void *professor(void *arg)
{
    printf("Professor wants to START lecture.\n");
    sem_wait(&turnstile);
    sem_wait(&professorBlock);
    printf("Professor STARTED the lecture.\n");
    sem_post(&professorBlock);
    sem_post(&turnstile);

    sleep(5);

    printf("Professor wants to END lecture.\n");
    sem_wait(&turnstile);
    sem_wait(&professorBlock);
    printf("Professor ENDED the lecture.\n");
    sem_post(&professorBlock);
    sem_post(&turnstile);

    pthread_exit(NULL);
}

int main()
{
    pthread_t prof, students[5];
    int ids[5];

    sem_init(&mutex, 0, 1);
    sem_init(&turnstile, 0, 1);
    sem_init(&professorBlock, 0, 1);

    pthread_create(&prof, NULL, professor, NULL);
    sleep(1);

    for (int i = 0; i < 5; i++)
    {
        ids[i] = i + 1;
        pthread_create(&students[i], NULL, student, &ids[i]);
        sleep(1);
    }

    pthread_join(prof, NULL);
    for (int i = 0; i < 5; i++)
        pthread_join(students[i], NULL);

    sem_destroy(&mutex);
    sem_destroy(&turnstile);
    sem_destroy(&professorBlock);

    return 0;
}

