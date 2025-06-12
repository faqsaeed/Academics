#include <stdio.h>
#include <pthread.h>
#include <semaphore.h>
#include <unistd.h>

sem_t charging_ports;     
sem_t waiting_area;       
sem_t attendant_signal;   
pthread_mutex_t log_mutex = PTHREAD_MUTEX_INITIALIZER;

void *attendant(void *arg) 
{
    while (1) 
    {
        sem_wait(&attendant_signal); 
        pthread_mutex_lock(&log_mutex);
        printf("Attendant: Logging charging event...\n");
        pthread_mutex_unlock(&log_mutex);
    }
    return NULL;
}

void *student(void *arg) 
{
    int id = *(int *)arg;

    if (sem_trywait(&charging_ports) == 0) 
    {
        
        printf("Student %d: Started charging.\n", id);
        sem_post(&attendant_signal); 

        sleep(2); 

        printf("Student %d: Finished charging.\n", id);
        sem_post(&charging_ports); 
        sem_post(&attendant_signal); // Notify attendant
    } 
    else if (sem_trywait(&waiting_area) == 0) 
    {
        printf("Student %d: Waiting for a charging port.\n", id);

        sem_wait(&charging_ports);
        sem_post(&waiting_area);   

        printf("Student %d: Got a charging port.\n", id);
        sem_post(&attendant_signal);

        sleep(5); 

        printf("Student %d: Finished charging.\n", id);
        sem_post(&charging_ports);
        sem_post(&attendant_signal);
    } 
    else 
    {
        printf("Student %d: Left. No room to wait.\n", id);
    }

    return NULL;
}

int main() 
{
    pthread_t student_threads[1000], attendant_thread;
    int student_ids[1000];

    sem_init(&charging_ports, 0, 3);
    sem_init(&waiting_area, 0, 2);
    sem_init(&attendant_signal, 0, 0);

    pthread_create(&attendant_thread, NULL, attendant, NULL);


    for (int i = 0; i < 1000 ; i++) 
    {
        student_ids[i] = i + 1;
        pthread_create(&student_threads[i], NULL, student, &student_ids[i]);
        sleep(2);
    }

    for (int i = 0; i < 1000; i++) 
        pthread_join(student_threads[i], NULL);
  
    sem_destroy(&charging_ports);
    sem_destroy(&waiting_area);
    sem_destroy(&attendant_signal);
    pthread_mutex_destroy(&log_mutex);

    return 0;
}

