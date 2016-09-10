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

}