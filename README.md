# SkeletonMultipleProcesses
CS 4760 2/6/2024 Hauschild Nancy B

## Project Description

This project includes two parts:

1. `oss.c`: A program that simulates the launching and controlling of multiple concurrent child processes.
2. `user.c`: The child process program which receives a number as an argument and iterates that many times to report its PID, parent PID and sleep.

To compile this project, use the included makefile with the `make` command:

make
This will create two executables, `oss` and `user`.


You can run the `oss` executable with several command line argument options:

oss [-h] [-n proc] [-s simul] [-t iter]

- `-h`       : Display help message
- `-n proc`  : Number of total children to launch
- `-s simul` : Number of children allowed to run simultaneously
- `-t iter`  : Number to pass to the user process
