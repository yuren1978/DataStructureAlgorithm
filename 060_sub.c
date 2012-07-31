#include <stdio.h>

/* Applies the mask to a set like {1, 2, ..., n} and prints it */
void printv(int mask[], int n) {
	int i;
	printf("{ ");
	for (i = 0; i < n; ++i)
		if (mask[i])
			printf("%d ", i + 1); /*i+1 is part of the subset*/
	printf("\b }\n");
}

/* Generates the next mask*/

//0,0,0,0 to 1,0,0,0
//1,0,0,0 to 0,1,0,0
//0,1,0,0 to 1,1,0,0
//1,1,0,0 to 0,0,1,0
//0,0,1,0 to 1,0,1,0


int next(int mask[], int n) {
	int i;
	for (i = 0; (i < n) && mask[i]; ++i)
		mask[i] = 0;

	if (i < n) {
		mask[i] = 1;
		printmask(mask);
		return 1;
	}
//	printmask(mask);
	return 0;
}

void printmask(int mask[]){
	for(int index=0; index<4; index++){
		printf("%d-", mask[index]);
	}
	printf("\n");
}

int main(int argc, char *argv[]) {
	int n = 4;
	int mask[4]={0}; /* Guess what this is */

	/* Print all the others */
	while (next(mask, n)){
		//printmask(mask);
		printv(mask, n);
	}
		

	return 0;
}
