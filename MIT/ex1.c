#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

#define MAX_INPUT_SIZE 1024
#define MAX_ARG_COUNT 100

int main() {
    char input[MAX_INPUT_SIZE];
    char *args[MAX_ARG_COUNT];
    int running = 1;

    while (running) {
        printf("mysh> ");
        if (fgets(input, MAX_INPUT_SIZE, stdin) == NULL) {
            break;
        }

        // Remove newline character
        input[strcspn(input, "\n")] = 0;

        // Tokenize the input
        int arg_count = 0;
        char *token = strtok(input, " ");
        while (token != NULL && arg_count < MAX_ARG_COUNT - 1) {
            args[arg_count++] = token;
            token = strtok(NULL, " ");
        }
        args[arg_count] = NULL;

        // Check for exit command
        if (arg_count > 0 && strcmp(args[0], "exit") == 0) {
            running = 0;
            continue;
        }

        // Fork a child process
        pid_t pid = fork();
        if (pid < 0) {
            perror("Fork failed");
            continue;
        }
        if (pid == 0) {
            // Child process
            if (execvp(args[0], args) == -1) {
                perror("Command execution failed");
            }
            exit(1);
        } else {
            // Parent process
            wait(NULL);
        }
    }

    printf("Exiting mysh\n");
    return 0;
}

