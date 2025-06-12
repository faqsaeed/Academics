#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>

int main(int argc, char *argv[]) {
    if (argc != 2) {
        fprintf(stderr, "Usage: %s input.txt\n", argv[0]);
        return 1;
    }

    int in_fd = open(argv[1], O_RDONLY);
    if (in_fd < 0) {
        perror("open input");
        return 1;
    }

    int out_fd = open("output.txt", O_WRONLY | O_CREAT | O_TRUNC, 0644);
    if (out_fd < 0) {
        perror("open output");
        return 1;
    }

    dup2(in_fd, STDIN_FILENO);
    dup2(out_fd, STDOUT_FILENO);
    close(in_fd);
    close(out_fd);

    char buf[1024];
    ssize_t bytesRead;
    while ((bytesRead = read(STDIN_FILENO, buf, sizeof(buf))) > 0) {
        printf("%.*s", (int)bytesRead, buf);  // Uses stdout
    }

    return 0;
}

