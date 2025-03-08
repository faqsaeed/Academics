#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <time.h>

void inputInFile(FILE* file, const int size)
{
    unsigned int seed = time(0);
    for(int i = 0; i < size; i++)
    {
        fprintf(file, "%d ", (rand_r(&seed) % 256));
    }
}

int main(int agrc, char*agrv[])
{
    if(agrc < 2)
	{
		printf("Pass a Number!!!\n");
		return(-1);
	}
    //execlp("touch", "touch", "input.txt", NULL);
    FILE* file;
    file = fopen("input.txt", "w");
    inputInFile(file, atoi(agrv[1]));
    fclose(file);
    return 0;   
}