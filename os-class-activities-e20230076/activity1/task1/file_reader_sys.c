#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>

int main(void) {
    int fd = open("output_sys.txt", O_RDONLY);

    if (fd == -1) {
        perror("open");
        return 1;
    }

    char buffer[256];
    ssize_t bytesRead;

    while ((bytesRead = read(fd, buffer, sizeof(buffer))) > 0) {
        if (write(STDOUT_FILENO, buffer, bytesRead) == -1) {
            perror("write");
            close(fd);
            return 1;
        }
    }

    if (bytesRead == -1) {
        perror("read");
        close(fd);
        return 1;
    }

    close(fd);
    return 0;
}
