#include "queue.h"
#include <stdio.h>
#include <string.h>

Queue* create_queue(){
    Queue* q = (Queue*) malloc (sizeof(Queue));
    q->first = NULL;
    q->last = NULL;
    return q;
}


void enqueue(Queue* Q, char* item){
	Node* temp = (Node*) malloc (sizeof(Node));
	temp->myString = strdup(item);
	temp->next = NULL;
	if (Q->first == NULL){
		Q->first = temp;
		
		Q->last = temp;
	}
	else{
		Q->last->next = temp;
		Q->last = temp;
	}
}

void print_queue(Queue *Q){
	Node* temp = Q->first;
	if (Q->first != NULL){
		while (temp->next != NULL){
			printf("%s\n", temp->myString);
			temp = temp->next;
		}
		
		printf("%s\n", Q->last->myString);
	}
	else{
		printf("Error\n");
	}
	;
}