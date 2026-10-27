
#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>
#include <string.h>

int main(void) {
    int fd = open("output_sys.txt", O_WRONLY | O_CREAT | O_TRUNC, 0644);

    if (fd == -1) {
        perror("open");
        return 1;
    }

    const char *message = "Hello from Linux system calls!\n";

    if (write(fd, message, strlen(message)) == -1) {
        perror("write");
        close(fd);
        return 1;
    }

    close(fd);

    printf("File created successfully using system calls.\n");

    return 0;
}
