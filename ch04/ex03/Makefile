all: main
	./main
main: main.c
	gcc -pthread locker.c locker_pthread.c main.c -o main
clean:
	rm main
