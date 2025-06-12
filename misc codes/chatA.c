#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <time.h>
#include <unistd.h>
#include <pthread.h>

#define MSG_SIZE 256

void* read_thread(void* arg) {
    int fd = open("pipe_BtoA", O_RDONLY);
    char buffer[MSG_SIZE];

    while (1) {
        if (read(fd, buffer, MSG_SIZE) > 0) {
            time_t now = time(NULL);
            printf("[User B | %s] %s\n", strtok(ctime(&now), "\n"), buffer);
        }
    }
    close(fd);
    return NULL;
}

int main() {
    mkfifo("pipe_AtoB", 0666);
    mkfifo("pipe_BtoA", 0666);

    pthread_t reader;
    pthread_create(&reader, NULL, read_thread, NULL);

    int fd = open("pipe_AtoB", O_WRONLY);
    char message[MSG_SIZE];

    while (1) {
        printf("You: ");
        fgets(message, MSG_SIZE, stdin);
        write(fd, message, strlen(message) + 1);
    }

    close(fd);
    return 0;
}

