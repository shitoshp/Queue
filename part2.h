#include <stdio.h>
#include <stdlib.h>

typedef struct fnode   //Frequency Node
{
	char *word;
	unsigned int freq;
	struct fnode *next;
} fnode;

void printlist(fnode *head);
fnode *readStringList(FILE *infile);
fnode *getMostFrequent (fnode *head, unsigned int num_to_select);
