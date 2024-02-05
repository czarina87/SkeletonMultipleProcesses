#===========================Makefile================================#
CC = gcc

all: oss user

oss: oss.c
	$(CC) -o oss oss.c

user: user.c
	$(CC) -o user user.c

clean:
	rm -f oss user