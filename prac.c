#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int main(){
	// FILE *fp;
	// fp = fopen("a.txt", "r");
	// char x[50];

	// while (!feof(fp)){
	// 	fgets(x, 50, fp);
	// 	printf("%s", x);
	// }
	// printf("Last: %s\n", x);

	// fclose(fp);
	char *str;
	char *abc = "apple";
   /* Initial memory allocation */
   	str = (char *) malloc(15);
	strcpy(str, "tutorialspoint");
	str = "new string";
	printf("String = %s\n",   str);
	printf("abcstring = %s\n", abc);
	//free(abc);

	// abc = "diid";
	// printf("%s\n", abc);





	return   0;
}