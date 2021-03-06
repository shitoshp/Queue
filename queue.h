#include <stdio.h>
#include <stdlib.h>

typedef struct Node Node;
struct Node{
    char *myString;
    Node* next;
};

typedef struct Queue Queue;
struct Queue{
    Node* first;
    Node* last;
};



Queue* create_queue();
void enqueue(Queue* Q, char* item);
char* dequeue(Queue* Q);
void print_queue(Queue *Q);
void flush_queue(Queue* Q);
void free_queue(Queue* Q);
