#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <semaphore.h>
#include <unistd.h>

#define MAX_CHIMPS 100

sem_t turnstileA, turnstileB;
pthread_mutex_t mutex = PTHREAD_MUTEX_INITIALIZER;

int waitingA = 0, waitingB = 0;
int direction = -1; // -1: no direction, 0: A to B, 1: B to A
int crossing = 0;

void* chimpanzee(void* arg) 
{
    int id = *(int*)arg;
    int myDirection = rand() % 2; // 0 for A->B, 1 for B->A
    printf("[Chimp %d] Arrived at Point %c\n", id, myDirection == 0 ? 'A' : 'B');

    pthread_mutex_lock(&mutex);

    if (myDirection == 0) 
        waitingA++;
    else 
        waitingB++;

    if (direction == -1) 
    {
        direction = myDirection;

        int toRelease = (myDirection == 0) ? waitingA : waitingB;

        int allowed = (toRelease < 5) ? toRelease : 5;

        for (int i = 0; i < allowed; i++) 
        {
            if (direction == 0) 
                sem_post(&turnstileA);
            else 
                sem_post(&turnstileB);
        }
    }
    pthread_mutex_unlock(&mutex);

    sleep(50000%10);


    if (myDirection == 0) 
        sem_wait(&turnstileA);
    else 
        sem_wait(&turnstileB);

    pthread_mutex_lock(&mutex);
    crossing++;
    pthread_mutex_unlock(&mutex);

    printf("[Chimp %d] Crossing from %c to %c...\n", id, myDirection == 0 ? 'A' : 'B', myDirection == 0 ? 'B' : 'A');
    sleep(1); 
    printf("[Chimp %d] Crossed from %c to %c!\n", id, myDirection == 0 ? 'A' : 'B', myDirection == 0 ? 'B' : 'A');

    pthread_mutex_lock(&mutex);
    crossing--;

    if (myDirection == 0) 
        waitingA--;
    else 
        waitingB--;

    if (crossing == 0) 
    {
        if ((myDirection == 0 && waitingB > 0) || (myDirection == 1 && waitingA > 0)) 
        {
            direction = 1 - myDirection;
            int toRelease = (direction == 0) ? waitingA : waitingB;
            int allowed = (toRelease < 5) ? toRelease : 5;

            for (int i = 0; i < allowed; i++) 
            {
                if (direction == 0) 
                    sem_post(&turnstileA);
                else 
                    sem_post(&turnstileB);
            }

        } 
        else if ((myDirection == 0 && waitingA > 0) || (myDirection == 1 && waitingB > 0)) {
            int toRelease = (myDirection == 0) ? waitingA : waitingB;
            int allowed = (toRelease < 5) ? toRelease : 5;

            for (int i = 0; i < allowed; i++) 
            {
                if (myDirection == 0) 
                    sem_post(&turnstileA);
                else 
                sem_post(&turnstileB);
            }
        } 
        else 
        {
            direction = -1;
        }
    }

    pthread_mutex_unlock(&mutex);
    return NULL;
}

int main(int argc, char* argv[]) 
{
    if (argc != 2) 
    {
        printf("Usage: %s <number_of_chimps>\n", argv[0]);
        return 1;
    }

    int n = atoi(argv[1]);
    if (n > MAX_CHIMPS) n = MAX_CHIMPS;

    pthread_t threads[n];
    int ids[n];

    sem_init(&turnstileA, 0, 0);
    sem_init(&turnstileB, 0, 0);

    srand(time(NULL));

    for (int i = 0; i < n; i++) 
    {
        ids[i] = i;
        pthread_create(&threads[i], NULL, chimpanzee, &ids[i]);
    }

    for (int i = 0; i < n; i++) 
        pthread_join(threads[i], NULL);
    

    sem_destroy(&turnstileA);
    sem_destroy(&turnstileB);

    return 0;
}
