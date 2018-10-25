CFLAGS=-Wall -Wextra

all: code

code: code-achievement1

code-achievement1: src/project-1.c base_elm singes
	gcc $(CFLAGS) base_elements.o singes.o src/project-1.c -o project

test: test-achievement1

test-achievement1: src/test-1.c base_elm
	gcc $(CFLAGS) base_elements.o src/test-1.c -o test-1 && ./test-1

base_elm: src/base_elements.c
	gcc $(CFLAGS) -c src/base_elements.c

singes: src/singes.c base_elm
	gcc $(CFLAGS) -c src/singes.c

clean:
	rm -f projet test-1
