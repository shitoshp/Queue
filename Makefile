all:
	gcc -o queue_test queue.c queue_test.c
	gcc -o most_freq part2.c part2_test.c

clean:
	rm -rf *.o *.out queue_test	