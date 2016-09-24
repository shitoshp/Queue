#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "part2.h"

void printlist(fnode* head){
	if(head == NULL){printf("head is null");}
	else{
		fnode* print_temp = head;
		
		while (print_temp->next != NULL){
			printf("Word: %s ", print_temp->word);
			printf("Frequency: %d\n", print_temp->freq);
			//printf("size: %zu\n", strlen(temp->word));
			print_temp = print_temp->next;
		}
		
		printf("Word: %s ", print_temp->word);
		printf("Frequency: %d\n", print_temp->freq);
	}
	
}
int readLine(FILE *infile, char * line_buffer){


    fgets(line_buffer, 255, infile);

    
    if (feof(infile)){
        return -1;
    }
    else{
        return 0;
    }
 }
fnode *readStringList(FILE *infile){
	//printf("here\n");
	if (infile == NULL){
		printf("Error opening file!\n");
	}
		//printf("bruh\n");

	char* line_buffer = (char*) malloc (256*sizeof(char));
	fnode* head = NULL;
	fnode* last = NULL;
	//printf("this");
	while (!feof(infile)){
		//printf("\n");
		fgets(line_buffer, 255, (FILE*)infile);
		//char* line_buffer;
		//if ((line_buffer = strchr(x, '\n')) != NULL)    *line_buffer = '\0';
		//printf("%s", x);
		//printf("%zu\n", strlen(line_buffer));
		//char* temp;
		//char* line_buffer = (char*) malloc (2);
		char* to_compare;
		if ((strchr((line_buffer), '\n')) != NULL){
			to_compare = (char*) malloc ((strlen(line_buffer)-1) * sizeof(char));
			strncpy(to_compare, line_buffer, strlen(line_buffer) - 1);
		}
		else{
			to_compare = strdup(line_buffer);
		}

		

		//strcpy(line_buffer, x);

		//when head is null, initiate a list
		if (head == NULL){
			fnode* temp = (fnode*) malloc (sizeof(fnode));
			if ((strchr((line_buffer), '\n')) != NULL){
				temp->word = (char*) malloc ((strlen(line_buffer)-1) * sizeof(char));
				strncpy(temp->word, line_buffer, strlen(line_buffer) - 1);
			}
			else{
				temp->word = strdup(line_buffer);
			}
			temp->freq = 1;
			temp->next = NULL;
			head = temp;
			last = temp;

		}

		//if list exists, check if word is there
		else{
			fnode* checker = head;
			fnode* finder = head;
			fnode* null_checker = head;
			int added = 0;
			while(null_checker != NULL){
				null_checker = checker->next;
										//printf("herewego\n");

				if (strcmp(checker->word, to_compare) == 0){
					checker->freq += 1;
					//printf("new freq: %d\n", checker->freq);
					added = 1;
					if (checker->next != NULL){
						checker = checker->next;
					}
					free(to_compare);
					break;

				}

				//else find appropriate place and add

				else{
					// printf("%s\n", to_compare);
					// printf("%s\n", checker->word);
					if(strcmp(to_compare, checker->word) < 0){
						//printf("buffer is less\n");
						fnode* temp = (fnode*) malloc (sizeof(fnode));
						if ((strchr((line_buffer), '\n')) != NULL){
							temp->word = (char*) malloc ((strlen(line_buffer)-1) * sizeof(char));
							strncpy(temp->word, line_buffer, strlen(line_buffer) - 1);
						}
						else{
							temp->word = strdup(line_buffer);
						}
						temp->freq = 1;
						if (finder == checker){
							//printf("%s\n", checker->word);
							head = temp;
							temp->next = checker;
							checker = head;
							finder = head;
							free(to_compare);
							added = 1;
							break;
						}
						while (finder->next != checker){
							finder = finder->next;
						}
						temp->next = checker;
						finder->next = temp;
						added = 1;
						if (checker->next != NULL){
							checker = checker->next;
						}
						free(to_compare);
						break;
					}
					else{
						if (checker->next != NULL){
							checker = checker->next;
						}
						
					}
					
				}
				
			}
			if (added == 0){
				//printf("buffer is greater\n");
				fnode* temp = (fnode*) malloc (sizeof(fnode));
				if ((strchr((line_buffer), '\n')) != NULL){
					temp->word = (char*) malloc ((strlen(line_buffer)-1) * sizeof(char));
					strncpy(temp->word, line_buffer, strlen(line_buffer) - 1);
				}
				else{
					temp->word = strdup(line_buffer);
				}
				temp->freq = 1;
				temp->next = NULL;
				checker->next = temp;
				last = temp;
				free(to_compare);
			}
		}

	}
	free(line_buffer);
	return head;
}

fnode *getMostFrequent (fnode *head, unsigned int num_to_select){
	
	//printf("dude");
	//insert first from given list, make it head of sorted list
	//printlist(head);
	fnode* sorted_head = (fnode*) malloc (sizeof(fnode));
	sorted_head->word = strdup(head->word);
	sorted_head->freq = head->freq;
	sorted_head->next = NULL;
	//printf("come on");
	fnode* sorted_new = (fnode*) malloc (sizeof(fnode)); //free this at end

	fnode* parent_head = head;
	fnode* sorted_end = sorted_head;
	int unique_freq = 0;
	//if given list has only 1 item, return
	if (head->next == NULL){
		return sorted_head;
	}
	else{
		fnode* parent_temp = parent_head->next;

		//insert "num" number of nodes to sorted list
		if (num_to_select > 1){
			
			for (int i = 1; i < num_to_select; ++i)
			{
				//printf("n");
				fnode* sorted_temp = (fnode*) malloc (sizeof(fnode)); 
				sorted_new->word = strdup(parent_temp->word);
				sorted_new->freq = parent_temp->freq;
				sorted_new->next = NULL;

				sorted_temp->word = strdup(sorted_new->word);
				sorted_temp->freq = sorted_new->freq;
				
				//if new is smaller than first, insert at beginning of sorted list
				if ((sorted_head->freq > sorted_new->freq) || (sorted_head->freq == sorted_new->freq)){
					if (sorted_head->freq > sorted_new->freq){
						unique_freq += 1;
					}
					sorted_temp->next = sorted_head;
					sorted_head = sorted_temp;	
					free(sorted_new->word);	
				}

				//if new is greater than first and i = 2, insert after head 
				else if ((sorted_head->freq < sorted_new->freq) && (i == 1)){
					unique_freq += 1;
					sorted_head->next = sorted_temp;
					sorted_temp->next = NULL;
					sorted_end = sorted_temp;
					free(sorted_new->word);
				}
				else if ((sorted_head->freq < sorted_new->freq) && (i > 1)){
					
					int added = 0;  //flag to see if added
					fnode* sorted_checker1 = sorted_head;
					

					while (sorted_checker1->next != NULL){
						fnode* sorted_checker2 = sorted_checker1->next;
						if ((sorted_new->freq < sorted_checker2->freq) || (sorted_new->freq == sorted_checker2->freq)) {
							if (sorted_new->freq < sorted_checker2->freq){
								unique_freq += 1;
							}
							sorted_checker1->next = sorted_temp;
							sorted_temp->next = sorted_checker2;
							free(sorted_new->word);
							added = 1;
							break;
						}
						else{
							sorted_checker1 = sorted_checker1->next;
						}

					}
					//if not added yet, add at end
					if (added == 0){
						unique_freq += 1;
						sorted_end->next = sorted_temp;
						sorted_temp->next = NULL;
						sorted_end = sorted_temp;
						free(sorted_new->word);
					}
				}
				parent_temp = parent_temp->next;
			
			}
		}
		//done inserting "num_to_select" number of nodes to sorted list
		printlist(sorted_head);
		printf("\n\n");
		//printf("pt: %s\n", parent_temp->word);
		//printf("sorted_head: %s\n", sorted_head->word);
		//printf("\n\n");
		//now, go to main list and start comparing and adding if greater than head of sorted list
		//int unique_freq = num_to_select;
		int no_of_bronze = 1;
		fnode* null_checker = parent_temp;
		while (null_checker != NULL){
			null_checker = parent_temp->next;
			sorted_new->word = strdup(parent_temp->word);
			sorted_new->freq = parent_temp->freq;
			sorted_new->next = NULL;

			if (sorted_new->freq == sorted_head->freq){

				fnode* sorted_temp = (fnode*) malloc (sizeof(fnode));
				sorted_temp->word = strdup(sorted_new->word);
				//printf("new addition: %s\n", sorted_temp->word);
				sorted_temp->freq = sorted_new->freq;
				sorted_temp->next = sorted_head;
				sorted_head = sorted_temp;
				//printlist(sorted_head);
				//printf("\n");
				free(sorted_new->word);
				no_of_bronze += 1;

			}
			else if(sorted_new->freq > sorted_head->freq){

				printf("new addition: %s\n", sorted_new->word);
				if (num_to_select == 1){
					if (no_of_bronze == 1){
						free(sorted_head->word);
						sorted_head->word = strdup(sorted_new->word);
						sorted_head->freq = sorted_new->freq;
					}
					else{
						fnode* sorted_temp = sorted_head;
						while (sorted_head->next != NULL){
							sorted_head = sorted_head->next;
							free(sorted_temp->word);
							free(sorted_temp);
							sorted_temp = sorted_head;
						}
						free(sorted_head->word);
						sorted_head->word = strdup(sorted_new->word);
						sorted_head->freq = sorted_new->freq;
					}
				}
				else{
					
					int added = 0;  //flag to see if added
					fnode* sorted_checker1 = sorted_head;
					fnode* to_replace = sorted_head;

					fnode* sorted_temp = (fnode*) malloc (sizeof(fnode));
					sorted_temp->word = strdup(sorted_new->word);
					sorted_temp->freq = sorted_new->freq;

					while (sorted_checker1->next != NULL){
						fnode* sorted_checker2 = sorted_checker1->next;
						if ((sorted_new->freq < sorted_checker2->freq) || (sorted_new->freq == sorted_checker2->freq)) {
							if (sorted_new->freq < sorted_checker2->freq){
								unique_freq += 1;
							}
							sorted_temp->next = sorted_checker2;
							sorted_checker1->next = sorted_temp;
							//sorted_head = sorted_head->next;
							//printlist(sorted_head);
							
							added = 1;
							break;
						}
						else{
							sorted_checker1 = sorted_checker1->next;
						}

					}
					//if not added yet, add at end
					if (added == 0){
						unique_freq += 1;
						sorted_checker1->next = sorted_temp;         //this might lskfjlasbgnf;kasgjasjgfvjasoijgfk
						sorted_temp->next = NULL;
						sorted_end = sorted_temp;
						//sorted_head = sorted_head->next;
					}
					if (unique_freq == num_to_select){

						if (no_of_bronze == 1){
							unique_freq -= 1;
							sorted_head = sorted_head->next;
							free(to_replace->word);
							free(to_replace);
							//free(sorted_new->word);
						}
						//if more than 1 at bronze
						else{
							for (int i = 0; i < no_of_bronze; ++i)
							{
								unique_freq -= 1;
								sorted_head = sorted_head->next;
								free(to_replace->word);
								free(to_replace);
								to_replace = sorted_head;
							}
							//free(sorted_new->word);
							//printf("\nSorted new list:\n");
							//printlist(sorted_head);
							//printf("sh: %s\n", sorted_head->word);
						}
					}
					free(sorted_new->word);
				}
				no_of_bronze = 1;
				fnode* sorted_bronze = sorted_head;
				while (sorted_bronze->freq == sorted_bronze->next->freq){
					no_of_bronze += 1;
					sorted_bronze = sorted_bronze->next;
				}
			}
			else{
				free(sorted_new->word);
			}
			parent_temp = parent_temp->next;
		}

	}	
	return sorted_head;
}