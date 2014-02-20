#include <iostream>
#include <vector>
#include <cassert>

int findFirstOccurance(int numbers[], int size, int target){
	int l=0; int r=size-1;
	while(l<r &&  target!=numbers[l]){
		int m=l+(r-l)/2;
		if(target<=numbers[m]){
			r=m;
		}
		else{
			l=m+1;
		}
	}
	if(target==numbers[l]) return l;
	return -1;
}

int main()
{
	int myNums[] = {1,1,2,2,2,2,2,2,3,4,5,6,6,6,6,6,6,6,6,6,6,6,6,6,6,6,6,7,8,9};
	int sizeOfNumbers=sizeof(myNums)/sizeof(*myNums);
	assert(0==findFirstOccurance(myNums, sizeOfNumbers, 1 ));
	assert(2==findFirstOccurance(myNums, sizeOfNumbers, 2 ));
	assert(8==findFirstOccurance(myNums, sizeOfNumbers, 3 ));
	//note, to invoke the method from main method, specify the startIndex=0 and endIndex = length-1
    //System.out.println("Occurance of num 2 is " + GetOccurrence(2, myNums, 0, myNums.length-1));
	//System.out.println("Occurance of num 6 is " + GetOccurrence(6, myNums, 0, myNums.length-1));
	return 0;
}