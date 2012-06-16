//http://basicalgos.blogspot.com/2012/02/3.html
//3. Find the number of an element in a sorted array
//For instance,  2223333444555,   num_occurrence(4) for this array is  3.

//We use two binary search to find the start and end index of  'num'. The time complexity of this is O(logN). N is the length of the array.
//To find the boundary, the two binaries search will not stop when an element that equals to 'num' is found. Instead, it continues until the boundary is reached.

#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

int NumberOfOccurance(int* array, int length, int numberToLookFor){
	int startIndex, endIndex;
	int start, end, middle;
	start=0;
	end=length-1;
	while (start<=end) {
		middle=(start+end)/2;
		if(array[middle]>=numberToLookFor){
			end=middle-1;
		}
		else {
			start=middle+1;
		}
	}
	startIndex=end+1;
	
	start=0;
	end=length-1;
	while (start<=end) {
		middle=(start+end)/2;
		if(array[middle]<=numberToLookFor){
			start=middle+1;
		}
		else {
			end=middle-1;
		}
	}
	endIndex=start-1;
	//printf("Start Index %d And End Index %d", startIndex, endIndex);
	return endIndex-startIndex+1;
}

int main(int argc, char *argv[]) {
	int a[]={1,1,1,2,2,2,2,3,3,3,3,4,4,4,5};
	int length=sizeof(a)/sizeof(*a);
	assert(3==NumberOfOccurance(a, length,1));
	assert(4==NumberOfOccurance(a, length,2));
	assert(4==NumberOfOccurance(a, length,3));
	assert(3==NumberOfOccurance(a, length,4));
	assert(1==NumberOfOccurance(a, length,5));
	return 0;
}