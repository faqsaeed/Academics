#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>

int main() {
    int in_fd = open("input.txt", O_RDONLY);
    int out_fd = open("output.txt", O_WRONLY | O_CREAT | O_TRUNC, 0644);

    if (in_fd < 0 || out_fd < 0) {
        perror("open");
        return 1;
    }

    dup2(in_fd, STDIN_FILENO);
    dup2(out_fd, STDOUT_FILENO);
    close(in_fd);
    close(out_fd);

    char buf[1024];
    ssize_t n;
    while ((n = read(STDIN_FILENO, buf, sizeof(buf))) > 0) {
        write(STDOUT_FILENO, buf, n);
    }

    return 0;
}

