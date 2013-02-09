#include <iostream>
#include <cassert>

using namespace std;

void Swap(int* numbers, int start, int end){
	int temp=numbers[start];
	numbers[start]=numbers[end];
	numbers[end]=temp;
}

int CountInverse(int* numbers, int startIndex, int endIndex, int number){
	for (int i=startIndex; i<=endIndex; ++i) {
		int firstNumber=numbers[i];
		if(firstNumber>number){
			return (endIndex-i+1);
		}
	}
	return 0;
}

int CrossInvesePairs(int* numbers, int firstStartIndex, int firstEndIndex, int secondStartIndex, int secondEndIndex){
	int inverseCount=0;
	for (int i=secondStartIndex; i<=secondEndIndex; ++i) {
		int secondNumber=numbers[i];
		inverseCount+=CountInverse(numbers,firstStartIndex,firstEndIndex, secondNumber);
	}
	return inverseCount;
}

int SortCountInvesePairs(int* numbers, int start, int end){
	if(start==end){
		return 0;
	}
	else if (start<end && (end-start==1)) {
		int inverseCount= (numbers[start]<=numbers[end])?0:1;
		if(numbers[start]>numbers[end]){
			Swap(numbers, start, end);
		}
		return inverseCount;
	}
	int middle=(start+end)/2;
	int firstHalf=SortCountInvesePairs(numbers, start, middle);
	int secondHalf=SortCountInvesePairs(numbers, middle+1, end);
	int cross=CrossInvesePairs(numbers, start, middle, middle+1, end);
	return firstHalf+secondHalf+cross;
}


int CountInvesePairs(int* numbers, int n){
	return SortCountInvesePairs(numbers, 0, n-1);
}


int main(int argc, char *argv[]) {
	//int a[]={1};
	//assert(0==CountInvesePairs(a,1)); 
	//int b[]={1,2};
	//assert(0==CountInvesePairs(b,2));
	//int c[]={2,1};
	//assert(1==CountInvesePairs(c,2));
	//int d[]={1,1};
	//assert(0==CountInvesePairs(d,2));
	int e[]={4,3,1,2};
	assert(5==CountInvesePairs(e,4));
}