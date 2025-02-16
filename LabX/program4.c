#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

int main() {
    FILE *file = fopen("pids.txt", "a");
    if (file == NULL) {
        printf("Failed to open file, creating it now\n");
        file = fopen("pids.txt", "w");
        if (file == NULL) {
            printf("File creation failed\n");
            return 1;
        }
    }

    pid_t pid = fork();
    if (pid == -1) {
        printf("Fork failed\n");
        fclose(file);
        return 1;
    }

    if (pid == 0) {
        fprintf(file, "Child process PID: %d\n", getpid());
        fclose(file);
        printf("Child process PID: %d written to file\n", getpid());
    } else {
        fprintf(file, "Parent process PID: %d\n", getpid());
        fclose(file);
        printf("Parent process PID: %d written to file\n", getpid());
        wait(NULL);
    }

    return 0;
}

