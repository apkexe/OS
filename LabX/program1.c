#include <stdio.h>
#include <unistd.h>

int main() {
    int i;
    for (i = 0; i < 3; i++) {
        pid_t pid = fork();
        if (pid == 0) {
            printf("Process ID: %d, Parent ID: %d\n", getpid(), getppid());
        } else if (pid > 0) {
            printf("Main process running with PID: %d\n", getpid());
        } else {
            printf("Fork failed!\n");
        }
    }
    return 0;
}
