#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

#define RowCount 4
#define ColCount 4

typedef enum {false, true} bool;


bool FindNumberInMatrix(int matrix[RowCount][ColCount], int number){
	bool foundValue=false;
	int row=0, column=ColCount-1;
	while (row<RowCount && column>=0) {
		if(matrix[row][column]==number){
			foundValue=true;
			break;
		}
		else if (matrix[row][column]>number) {
			--column;
		}
		else if (matrix[row][column]<number){
			++row;
		} 
	}
	return foundValue;
}

int main(int argc, char *argv[]) {
	int a[4][4]={
		{1,2,8,9},
		{2,4,9,12},
		{4,7,10,13},
		{6,8,11,15}
	};
	
	assert(true==FindNumberInMatrix(a,2));
	assert(true==FindNumberInMatrix(a,15));
	assert(true==FindNumberInMatrix(a,6));
	assert(false==FindNumberInMatrix(a,16));	
	return 0;
}