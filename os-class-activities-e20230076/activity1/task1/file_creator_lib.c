
#include <stdio.h>

int main(void) {
    FILE *file = fopen("output.txt", "w");

    if (file == NULL) {
        perror("fopen");
        return 1;
    }

    fprintf(file, "Hello from the C standard library!\n");

    fclose(file);

    printf("File created successfully.\n");

    return 0;
}

