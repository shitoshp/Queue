#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "part2.h"


fnode *readStringList(FILE *infile){
	if (infile == NULL){
		printf("Error opening file!\n");
	}
	char* x = (char*) malloc (sizeof(char));
	fnode* head = NULL;
	fnode* last = NULL;

	while (!feof(infile)){
		fgets(x, 255, (FILE*)infile);
		printf("%s\n", x);

		//when head is null, initiate a list
		if (head == NULL){
			fnode* temp = (fnode*) malloc (sizeof(fnode));
			temp->word = strdup(x);
			temp->freq = 1;
			temp->next = NULL;
			head = temp;
			last = temp;
		}

		//if list exists, check if word is there
		else{
			fnode* checker = head;
			int added = 0;
			do{
				//if matches, just increment frequency
				if (checker->word == x){
					checker->freq += 1;
					added = 1;
				}

				//else find appropriate place and add
				else{
					if(strcmp(x, checker->word) < 0){
						fnode* temp = (fnode*) malloc (sizeof(fnode));
						temp->word = strdup(x);
						temp->freq = 1;
						temp->next = head;
						head = temp;
						added = 1;
						break;
					}
					else{
						checker = checker->next;
					}
				}
			}while(checker->next != NULL);
			if (added == 0){
				fnode* temp = (fnode*) malloc (sizeof(fnode));
				temp->word = strdup(x);
				temp->freq = 1;
				temp->next = NULL;
				checker->next = temp;
				last = temp;
			}
		}

	}	
	fclose(infile);
	return head;
}

fnode *getMostFrequent (fnode *head, unsigned int num_to_select){
	
	//insert first from given list, make it head of sorted list
	fnode* sorted_head = (fnode*) malloc (sizeof(fnode));
	sorted_head->word = strdup(head->word);
	sorted_head->freq = head->freq;
	sorted_head->next = NULL;

	fnode* sorted_new = (fnode*) malloc (sizeof(fnode)); //free this at end

	fnode* parent_head = head;
	fnode* sorted_end = sorted_head;
	
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
				fnode* sorted_temp = (fnode*) malloc (sizeof(fnode)); 
				sorted_new->word = strdup(parent_temp->word);
				sorted_new->freq = parent_temp->freq;
				sorted_new->next = NULL;

				sorted_temp->word = strdup(sorted_new->word);
				sorted_temp->freq = sorted_new->freq;
				
				//if new is smaller than first, insert at beginning of sorted list
				if ((sorted_head->freq > sorted_new->freq) || (sorted_head->freq == sorted_new->freq)){
					sorted_temp->next = sorted_head;
					sorted_head = sorted_temp;	
					free(sorted_new->word);	
				}

				//if new is greater than first and i = 2, insert after head 
				else if ((sorted_head->freq < sorted_new->freq) && (i == 1)){
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

		//now, go to main list and start comparing and adding if greater than head of sorted list
		more_than_one_bronze = 0;
		while (parent_temp->next != NULL){
			sorted_new->word = strdup(parent_temp->word);
			sorted_new->freq = parent_temp->freq;
			sorted_new->next = NULL;

			if (sorted_new->freq == sorted_head->freq){
				fnode* sorted_temp = (fnode*) malloc (sizeof(fnode));
				sorted_temp->word = strdup(sorted_new->word);
				sorted_temp->freq = sorted_new->freq;
				sorted_temp->next = sorted_head;
				sorted_head = sorted_temp;
				free(sorted_new->word);
				more_than_one_bronze += 1;
			}
			else if(sorted_new->freq > sorted_head->freq){
				if (num_to_select == 1){
					if (more_than_one_bronze == 0){
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
					if (more_than_one_bronze == 0){
						int added = 0;  //flag to see if added
						fnode* sorted_checker1 = sorted_head;
						fnode* to_replace = sorted_head;

						fnode* sorted_temp = (fnode*) malloc (sizeof(fnode));
						sorted_temp->word = strdup(sorted_new->word);
						sorted_temp->freq = sorted_new->freq;

						while (sorted_checker1->next != NULL){
							fnode* sorted_checker2 = sorted_checker1->next;
							if ((sorted_new->freq < sorted_checker2->freq) || (sorted_new->freq == sorted_checker2->freq)) {
								
								sorted_temp->next = sorted_checker2;
								sorted_checker1->next = sorted_temp;
								sorted_head = sorted_head->next;
								
								added = 1;
								break;
							}
							else{
								sorted_checker1 = sorted_checker1->next;
							}

						}
						//if not added yet, add at end
						if (added == 0){
							sorted_checker2->next = sorted_temp;
							sorted_temp->next = NULL;
							sorted_end = sorted_temp;
							sorted_head = sorted_head->next;
						}
						free(to_replace->word);
						free(to_replace);
						free(sorted_new->word);
					}
					//if more than 1 at bronze
					else{

					}
				}
			}
			else{
				free(sorted_new->word);
			}
			parent_temp = parent_temp->next;
		}

	}	
}