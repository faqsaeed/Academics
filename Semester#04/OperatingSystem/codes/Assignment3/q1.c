#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <unistd.h>
#include <stdbool.h>
#include <time.h>

// Shared state
bool isGreenLight = false;
bool gameOver = false;
int score = 0;
pthread_mutex_t lock;

void* toggleLight(void* arg) 
{
    while (1) 
    {
        pthread_mutex_lock(&lock);
        if (gameOver) 
        {
            pthread_mutex_unlock(&lock);
            break;
        }

        isGreenLight = rand() % 2;
        pthread_mutex_unlock(&lock);
        sleep(2); // Light changes every 2 seconds
    }
    return NULL;
}

void* displayLight(void* arg) 
{
    while (1) 
    {
        pthread_mutex_lock(&lock);
        if (gameOver) 
        {
            pthread_mutex_unlock(&lock);
            break;
        }

        system("clear");
        printf("%s Light\n", isGreenLight ? "Green" : "Red");
        pthread_mutex_unlock(&lock);

        usleep(500000); // 500ms refresh
    }
    return NULL;
}

void playerInput() 
{
    while (1) 
    {
        getchar(); // Wait for Enter key

        pthread_mutex_lock(&lock);
        if (gameOver) 
        {
            pthread_mutex_unlock(&lock);
            break;
        }

        system("clear");
        if (isGreenLight) 
        {
            score++;
            printf("Correct! Score: %d\n", score);
        } 
        else 
        {
            gameOver = true;
            printf("Game Over! Final Score: %d\n", score);
        }

        pthread_mutex_unlock(&lock);
    }
}

int main() 
{
    pthread_t lightThread, displayThread;
    pthread_mutex_init(&lock, NULL);
    srand(time(NULL)); 

    pthread_create(&lightThread, NULL, toggleLight, NULL);
    pthread_create(&displayThread, NULL, displayLight, NULL);

    playerInput();

    pthread_join(lightThread, NULL);
    pthread_join(displayThread, NULL);

    pthread_mutex_destroy(&lock);
    return 0;
}
