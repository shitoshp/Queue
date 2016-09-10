#include <stdio.h>
#include <stdlib.h>
#include "queue.h"

int main(){
	Queue* Q = create_queue();
	char* x = "ball";
	char* j = "cat";
	char* l = "dog";
	enqueue(Q, x);
	enqueue(Q, j);
	enqueue(Q, l);
	print_queue(Q);
	return 0;
}