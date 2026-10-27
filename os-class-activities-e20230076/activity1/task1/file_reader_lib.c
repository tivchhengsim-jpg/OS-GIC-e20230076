#include <stdio.h>

int main(void) {
    FILE *file = fopen("output.txt", "r");

    if (file == NULL) {
        perror("fopen");
        return 1;
    }

    char buffer[256];

    while (fgets(buffer, sizeof(buffer), file) != NULL) {
        printf("%s", buffer);
    }

    fclose(file);

    return 0;
}

