#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <unistd.h>

int main(int argc, char *argv[]) {
    if(argc != 2) {
        fprintf(stderr, "Usage: %s <num_iterations>\n", argv[0]);
        return 1;
    }

    int iterations = atoi(argv[1]);
    pid_t pid = getpid();
    pid_t ppid = getppid();

    for(int i = 0; i < iterations; i++) {
        printf("USER PID:%d PPID:%d Iteration:%d before sleeping\n", pid, ppid, i+1);
        sleep(1);
        printf("USER PID:%d PPID:%d Iteration:%d after sleeping\n", pid, ppid, i+1);
    }

    return 0;
}