#include <stdio.h>
#include <unistd.h>
#include <string.h>

int main() {
    int fd[2];
    char buffer[100];
    if (pipe(fd) == -1) {
        printf("Pipe creation failed\n");
        return 1;
    }
    pid_t pid = fork();
    if (pid == 0) {
        close(fd[1]);
        read(fd[0], buffer, sizeof(buffer));
        printf("Child got message: %s\n", buffer);
    } else if (pid > 0) {
        close(fd[0]);
        char msg[] = "Hi from parent!";
        write(fd[1], msg, strlen(msg) + 1);
    } else {
        printf("Fork failed\n");
    }
    return 0;
}
