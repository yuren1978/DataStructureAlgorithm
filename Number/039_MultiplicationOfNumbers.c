#include <stdio.h>
#include <stdlib.h>

//There is an array A[N] of N numbers. You have to compose an array Output[N] such that Output[i] will be equal to multiplication of all the elements of A[N] except A[i]. Solve it without division operator and in O(n).
//For example Output[0] will be multiplication of A[1] to A[N-1] and Output[1] will be multiplication of A[0] and from A[2] to A[N-1].
// 1,2,3,4,5
// 

void Multiply(int* input, int length, int* output){
}

int main(){
	int a[]={1,2,3,4,5};
	int b[]={1,1,1,1,1};
	int length=sizeof(a)/sizeof(*a);
	Multiply(a, length, b);
	for (int i=0; i<length; i++) {
		printf("%d\t", b[i]);
	}
	return 0;
}