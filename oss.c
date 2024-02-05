#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>
#include <getopt.h>

int main(int argc, char *argv[]) {
    int proc = 0, simul = 0, iter = 0;
    int option;

    while((option = getopt(argc, argv, "hn:s:t:")) != -1) {
        switch (option) {
            case 'h':
                printf("oss [-h] [-n proc] [-s simul] [-t iter]\n");
                return 0;
            case 'n':
                proc = atoi(optarg);
                break;
            case 's':
                simul = atoi(optarg);
                break;
            case 't':
                iter = atoi(optarg);
                break;
            default:
                fprintf(stderr, "Invalid arguments provided.\n");
                return 1;
        }
    }

    char iterations[10];
    sprintf(iterations, "%d", iter);
    char *args[] = {"./user", iterations, NULL};

    for(int i = 0; i < proc; i++) {
        pid_t pid = fork();
        if(pid == 0) { // in child process
            execvp(args[0], args);
        }
        else { // in parent process
            if(i != 0 && i % simul == 0) {
                // wait for a child to finish before continuing
                wait(NULL);
            }
        }
    }

    while(wait(NULL) > 0); // wait for any remaining children to finish

    return 0;
}