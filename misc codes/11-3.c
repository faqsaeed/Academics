#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>
#include <ctype.h>

int main() {
    int fd = open("original.txt", O_RDWR);
    if (fd < 0) {
        perror("open");
        return 1;
    }

    int copy_fd = dup(fd);
    if (copy_fd < 0) {
        perror("dup");
        return 1;
    }

    char buf[1024];
    ssize_t bytes = read(fd, buf, sizeof(buf));
    if (bytes < 0) {
        perror("read");
        return 1;
    }

    for (int i = 0; i < bytes; i++) {
        buf[i] = tolower((unsigned char)buf[i]);
    }

    lseek(copy_fd, 0, SEEK_SET);
    write(copy_fd, buf, bytes);
    close(fd);
    close(copy_fd);

    return 0;
}

