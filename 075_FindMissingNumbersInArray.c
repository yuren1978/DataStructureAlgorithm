#include <stdio.h>
#include <assert.h>

int main(int argc, char *argv[]) {
	int a[]={3,2,1,5}; //the range is from 1 to 7
	int length=sizeof(a)/sizeof(*a);
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
	assert(4==MissingNumber);
}