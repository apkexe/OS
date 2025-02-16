/* Exercise 6: Simple File Operations in C */
#include <stdio.h>
#include <stdlib.h>

int main() {
    FILE *file;
    char filename[] = "example.txt";
    char text[] = "Hello THMMY AUTh! Enjoy Tsiknopempti!";
    char buffer[100];

    // Open file for writing
    file = fopen(filename, "w");
    if (file == NULL) {
        printf("Error opening file for writing!\n");
        return 1;
    }
    fprintf(file, "%s", text);
    fclose(file);

    // Open file for reading
    file = fopen(filename, "r");
    if (file == NULL) {
        printf("Error opening file for reading!\n");
        return 1;
    }
    if (fgets(buffer, sizeof(buffer), file) != NULL) {
        printf("File content: %s\n", buffer);
    }
    fclose(file);

    return 0;
}

