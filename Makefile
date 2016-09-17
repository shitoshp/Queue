all:
	gcc -o queue_test queue.c queue_test.c

clean:
	rm -rf *.o *.out queue_test	