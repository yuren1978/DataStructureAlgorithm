#include <stdio.h>
#include <assert.h>

int firstMissingPositive(int A[], int n) 
{
  for (int i=0; i<n; ++i){
	while (1<=A[i] && A[i] <=n && A[A[i]-1]!=A[i]){
		int temp=A[i];
		A[i]=A[A[i]-1];
		A[A[i]-1]=temp;
	}
  }
    
  for (int i=0; i<n; ++i)
    if (A[i] != i+1)
       return i+1;

  return n+1;   
}

int firstMissingPositiveXOr(int a[], int length){
	int Sum=0;
		for (int index=0; index<length; index++) {
			Sum=Sum^a[index];
		}
		printf("%d\n", Sum);
		int SumAll=0;
		for (int index=1; index<=5; index++) {
			SumAll=SumAll^index;
		}
		printf("%d\n", SumAll);
		int MissingNumber=Sum^SumAll;
		printf("%d\n", MissingNumber);
		return MissingNumber;
}

int main(int argc, char *argv[]) {
	int a[]={3,2,1,5}; //the range is from 1 to 7
	int length=sizeof(a)/sizeof(*a);
	
	assert(4==firstMissingPositiveXOr(a, length));
	assert(4==firstMissingPositive(a, length));
}