#include <stdio.h>
#include <limits.h>

int maxSubArray(int A[], int n) {
    // Start typing your C/C++ solution below
    // DO NOT write int main() function
    int maxSum=INT_MIN;
    int sumSoFar=0;
    for (int i = 0; i < n; ++i){
    	sumSoFar+=A[i];
    	maxSum=max(maxSum, sumSoFar);
    	if(sumSoFar<0){
    		sumSoFar=0;
    	}
    }
    return maxSum;
}

int main(int argc, char *argv[]) {
	int a[]={1,-1};
	int length=sizeof(a)/sizeof(*a);
	int maxSum=FindMaximuSubArray(a, length);
	printf("Max Sum is %d", maxSum);
}