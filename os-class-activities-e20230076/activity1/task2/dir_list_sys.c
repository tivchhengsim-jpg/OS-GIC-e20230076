#define _GNU_SOURCE
#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>
#include <sys/syscall.h>
#include <linux/types.h>

struct linux_dirent64 {
    unsigned long long d_ino;
    long long d_off;
    unsigned short d_reclen;
    unsigned char d_type;
    char d_name[];
};

int main(void) {
    int fd = open(".", O_RDONLY | O_DIRECTORY);

    if (fd == -1) {
        perror("open");
        return 1;
    }

    char buffer[4096];
    long bytesRead;

    while ((bytesRead = syscall(SYS_getdents64, fd, buffer, sizeof(buffer))) > 0) {
        for (long pos = 0; pos < bytesRead;) {
            struct linux_dirent64 *entry =
                (struct linux_dirent64 *)(buffer + pos);

            printf("%s\n", entry->d_name);
            pos += entry->d_reclen;
        }
    }

    if (bytesRead == -1) {
        perror("getdents64");
        close(fd);
        return 1;
    }

    close(fd);
    return 0;
}
