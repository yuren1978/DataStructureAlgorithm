//from he hao tao book, reorder array with two points , odd left, even right
//
#include <stdio.h>

void printArray(int A[], int n){
	for (int i = 0; i < n; ++i){
		printf("%d\t", A[i]);
	}
	printf("\n");
}

void swap(int A[], int i, int j){
	int temp=A[i];
	A[i]=A[j];
	A[j]=temp;
}

void arrayOrder(int A[] , int n){
	int i=0; int j=n-1;
	while(i<j){
		if(0==A[i]%2 && 1==A[j]%2){
			swap(A, i, j);
			i++; j--;				
		}
		else{
			if(1==A[i]%2)
				i++;
			if(0==A[j]%2)
				j--;
		}
	}
}

int main(int argc, char *argv[]) {
	int A[]={2,1,5,3,8,9,12,8, 99};
	int arraySize=sizeof(A)/sizeof(*A);
	arrayOrder(A, arraySize);
	printArray(A, arraySize);
}