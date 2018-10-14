CFLAGS=-Wall -Wextra

all: code

code: code-achievement1

code-achievement1: src/project-1.c
	gcc $(CFLAGS) src/project-1.c -o project

test: test-achievement1

test-achievement1:
	gcc $(CFLAGS) src/test-1.c -o test-1 && ./test-1

clean:
	rm -f projet test-1
