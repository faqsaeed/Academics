#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <unistd.h>
#include <stdbool.h>
#include <time.h>

volatile bool isGreenLight = false;
volatile bool gameOver = false;
int score = 0;
pthread_mutex_t lock;

void* toggleLight(void* arg) 
{
    srand(time(NULL));
    while (!gameOver) 
    {
        isGreenLight = rand() % 1; // Randomly set to true (Green) or false (Red)    
        sleep(2); // Change every 2 seconds
    }
    return NULL;
}

void* displayLight(void* arg)
 {

    while (!gameOver) 
    {
        system("clear");

        if (isGreenLight) 
        {
            printf("Green Light\n");
        } 
        else 
        {
            printf("Red Light\n");
        }
        usleep(500000); // Print status every 500ms
    }
    return NULL;
}

void playerInput() 
{
    while (!gameOver) 
    {
        getchar(); 
        system("clear");
        if (gameOver) 
        {
            break;
        }
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
        
    }
}

int main() {
    pthread_t lightThread, displayThread;
    
    pthread_create(&lightThread, NULL, toggleLight, NULL);
    pthread_create(&displayThread, NULL, displayLight, NULL);
    
    playerInput();
    
    pthread_join(lightThread, NULL);
    pthread_join(displayThread, NULL);
    return 0;
}

/*
Is it ever possible that the user presses 'Enter' when the light is green, yet the game becomes over?
Yes, due to race conditions. Since `isGreenLight` is shared among threads, it may change before 
the input is processed. 
*/
