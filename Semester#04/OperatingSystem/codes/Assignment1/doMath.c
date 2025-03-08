#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <string.h>

int main(int argc, char* argv[])
{
    if(argc < 3)
    {
        printf("Insufficent number of arguments passed\n");
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
        execlp("gcc", "gcc", "square.c", "-o", "square", NULL);
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
            execlp("gcc", "gcc", "double.c", "-o", "double", NULL);
            perror("execlp ./createFile failed");
            exit(1);
        }
        else
        {
            wait(NULL);
        }
    }

    int num = atoi(argv[argc - 1]);
    int fd[2];

    for(int i = argc - 2; i != 0; i--)
    {
        if(pipe(fd) == -1)
        {
            printf("Pipe failed");
            return 0;
        }

        pid1 = fork();
        if(pid1 < 0)
        {
            printf("\nFork Failed!!\n");
            return(-1);
        }
        if(pid1 == 0)
        {
            close(fd[0]);
            char numstr[10], pipestr[10];
            sprintf(numstr, "%d", num);
            sprintf(pipestr, "%d", fd[1]);

            if (strcmp(argv[i], "double") == 0) 
            {
                execlp("./double", "./double", numstr, pipestr, NULL);
                perror("execlp for double failed");
            } 
            else if (strcmp(argv[i], "square") == 0) 
            {
                execlp("./square", "./square", numstr, pipestr, NULL);
                perror("execlp for square failed");
            }
            exit(1);
        }
        else
        {
            close(fd[1]);
            wait(NULL);
            if (read(fd[0], &num, sizeof(num)) < 0) 
            {
                perror("read failed");
                return 1;
            }            
            close(fd[0]);
        }
    }
    printf("\nThe Final Answer is %d \n", num);
    return 0;
}
