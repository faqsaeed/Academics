#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main(int argc, char* argv[])
{
    if(argc != 3)
    {
        printf("Incompatable number of arguments paseed in Square.c");
        return 0;
    }

    int n = atoi(argv[1]);
    int fd = atoi(argv[2]);
    int result = n * n;
    write(fd, &result, sizeof(result));
}