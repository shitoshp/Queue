#include <stdio.h>
#include <stdlib.h>
#include "part2.h"

int main(int argc, char* argv[]){
//int main(){
	printf("mainfile\n");
	FILE* fp;
	//fp = fopen("string.txt", "r");
	//printlist(readStringList(fp));
	// fclose(fp);
	//printf("\n\n\n");
	unsigned int most_freq = atoi(argv[1]);
	fp = fopen(argv[2], "r");
	//readStringList(fp);
	printlist(getMostFrequent(readStringList(fp), most_freq));

	fclose(fp);
	return 0;
}