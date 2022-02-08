CC=gcc
FLAGS=-Werror -Wall -Wextra -std=c11

FILE=main


all: 
	make task
task: $(FILE).c
	$(CC) -o ./a.out $(FLAGS) $(FILE).c

clean:
	rm -rf  *.o *.out