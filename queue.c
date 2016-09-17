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

char* dequeue(Queue* Q){
	if ((Q->first != NULL) && (Q->first == Q->last)){
		
		Node* temp = Q->first;
		printf("%s\n", temp->myString);
		char* dequeued = temp->myString;
		Q->first = NULL;
    	Q->last = NULL;
		free(temp->myString);
		free(temp);
		return dequeued;
	}
	else if ((Q->first != NULL) && (Q->first != Q->last)){
		Node* temp = Q->first;
		printf("%s\n", temp->myString);
		char* dequeued = temp->myString;
		Q->first = temp->next;
    	free(temp->myString);
		free(temp);	
		return dequeued;
	}
	else{
		printf("Invalid queue\n");
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
}

void flush_queue(Queue* Q){
	Node* temp1 = Q->first;
	Node* temp2 = Q->first;
	if (Q->first != NULL){
		while (temp2->next != NULL){
			//printf("%s\n", temp->myString);
			temp1 = temp2;
			temp2 = temp2->next;
			free(temp1->myString);
			free(temp1);
		}
		
		free(temp2->myString);
		free(temp2);
		Q->first = NULL;
    	Q->last = NULL;
	}
	else{
		printf("Error\n");
	}
}

void free_queue(Queue* Q){
	flush_queue(Q);
	free(Q);
}

