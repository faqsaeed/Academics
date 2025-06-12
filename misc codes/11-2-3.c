#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>

int main() {
    int fd[2];
    pipe(fd);

    if (fork() == 0) {
        // Child: man ls
        dup2(fd[1], STDOUT_FILENO);
        close(fd[0]);
        close(fd[1]);
        execlp("man", "man", "ls", NULL);
        perror("execlp man");
    } else {
        if (fork() == 0) {
            // Grandchild: grep ls > file.txt
            int out_fd = open("file.txt", O_WRONLY | O_CREAT | O_TRUNC, 0644);
            dup2(fd[0], STDIN_FILENO);
            dup2(out_fd, STDOUT_FILENO);
            close(fd[0]);
            close(fd[1]);
            execlp("grep", "grep", "ls", NULL);
            perror("execlp grep");
        }
    }

    close(fd[0]);
    close(fd[1]);

    return 0;
}

