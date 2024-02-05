# SkeletonMultipleProcesses
CMP SCI 4760

Real-time process communication simulation using fork() and exec().

## Description

This project includes two parts:

1. `oss.c`: A program that simulates the launching and controlling of multiple concurrent child processes.
2. `user.c`: The child process program which receives a number as an argument and iterates that many times to report its PID, parent PID and sleep.

## Compilation

To compile this project, use the included makefile with the `make` command:

make
This will create two executables, `oss` and `user`.

## Usage

You can run the `oss` executable with several command line argument options:

oss [-h] [-n proc] [-s simul] [-t iter]

- `-h`       : Display help message
- `-n proc`  : Number of total children to launch
- `-s simul` : Number of children allowed to run simultaneously
- `-t iter`  : Number to pass to the user process

The `user` executable is intended to be run by `oss`, and is not designed to be run directly by the user.