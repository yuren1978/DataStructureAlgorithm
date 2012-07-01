#include "stdio.h"
#include "stdlib.h"
#include "assert.h"


int FindPosInArray(int* array, int length, int number){
	int position=-1;
	int start=0;
	int end=length-1;
	
	while (start<=end) {
		int middle=(start+end)/2;
		if(array[middle]==number){
			position=middle;
			break;
		}
		else {
			if(array[middle+1]<array[end]){
				if(number>=array[middle+1] && number<=array[end]){
					start=middle+1;
				}
				else {
					end=middle-1;
				}
			}
			else {
				if(number<=array[middle-1] && number>=array[0] ){
					end=middle-1;
				}
				else {
					start=middle+1;
				}
			}
		}
	}
	return position;
}


int main(int argc, char const *argv[])
{

	int a[]={7,8,9, 1,2,3,4,5,6};
	int length=sizeof(a)/sizeof(*a);	
	assert(0==FindPosInArray(a, length,7));
	assert(1==FindPosInArray(a, length,8));
	assert(2==FindPosInArray(a, length,9));
	assert(3==FindPosInArray(a, length,1));
	assert(4==FindPosInArray(a, length,2));
	assert(5==FindPosInArray(a, length,3));
	assert(6==FindPosInArray(a, length,4));
	assert(7==FindPosInArray(a, length,5));
	assert(8==FindPosInArray(a, length,6));
	return 0;
}