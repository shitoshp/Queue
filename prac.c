#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int main(){
	// FILE *fp;
	// fp = fopen("string.txt", "r");
	// char* x = (char*) malloc (256 * sizeof(char));
	// char* k;
	// int index;
	// while (!feof(fp)){
	// 	fgets(x, 255, fp);
	// 	printf("%s", x);
	// }

	// fclose(fp);

	// char *string = "qwerty\n";
	// char *e;
	// int index;

	// e = strchr(string, '\n');
	// index = (int)(e - string);

	// char *maal = (char*) malloc (index+1);
 //    strncpy(maal, string, index);
 //    printf("%s", string);
 //    printf("%s", maal);
 //    printf("%s", string); 

	char* x = "dog";
	char* y = "cat\n";
	const char k = '\n';

	char* z = (char*) malloc ((strlen(y)-1) * sizeof(char));
	strncpy(z, y, strlen(y) - 1);

	// printf("%zu\n", strlen(x));
	// printf("%zu\n", strlen(z));

	if ((strchr(y, 'c')) != NULL)
		printf("good");

	// if ((strchr(x, "k")) != NULL)
	// 	printf("bad");
	
	return   0;
}