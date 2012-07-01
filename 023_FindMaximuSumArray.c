#include <stdio.h>
#include <limits.h>

int FindMaximuSubArray(int* array, int length, int* maxValue){
	if(length==0)
		return 0;
	int sumSoFar=0;
	*maxValue=0;
	for (int index=0; index<length; index++) {
		sumSoFar+=array[index];
		if(sumSoFar>(*maxValue)){//
			*maxValue=sumSoFar;	
		}
		if(sumSoFar<0){//reset the sum and max
			sumSoFar=0;
		}
	}
	return 1;
}

int main(int argc, char *argv[]) {
	int maxValue=0;
	int a[]={1,-1};
	int length=sizeof(a)/sizeof(*a);
	int maxSum=FindMaximuSubArray(a, length, &maxValue );
	printf("Max Sum is %d", maxValue);
}