#include <stdio.h>
#include <unistd.h>
#include <signal.h>

void signal_handler(int sig) {
    printf("Signal received: %d\n", sig);
}

int main() {
    pid_t pid = fork();
    if (pid == 0) {
        signal(SIGUSR1, signal_handler);
        while (1) {
            sleep(1);
        }
    } else if (pid > 0) {
        sleep(2);
        kill(pid, SIGUSR1);
    } else {
        printf("Fork failed\n");
    }
    return 0;
}
