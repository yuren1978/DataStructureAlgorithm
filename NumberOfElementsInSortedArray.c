//http://basicalgos.blogspot.com/2012/02/3.html
//3. Find the number of an element in a sorted array
//For instance,  2223333444555,   num_occurrence(4) for this array is  3.

//We use two binary search to find the start and end index of  'num'. The time complexity of this is O(logN). N is the length of the array.
//To find the boundary, the two binaries search will not stop when an element that equals to 'num' is found. Instead, it continues until the boundary is reached.

#include <stdio.h>
#include <stdlib.h>

int NumberOfOccurance(int* array, int length, int numberToLookFor){
	int startIndex, endIndex;
	int begin, end, middle;
}

int main(int argc, char *argv[]) {
	int a[]={1,1,1,2,2,2,2,3,3,3,3,4,4,4,5};
	return 0;
}