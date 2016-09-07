#include <stdio.h>
#include <stdlib.h>
typedef struct Node Node;
struct Node{
    char *myString;
    Node* next
};

queue* create_queue();
