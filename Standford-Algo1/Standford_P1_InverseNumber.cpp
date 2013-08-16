#include <iostream>
#include <fstream>
#include <cassert>
#include <vector>

using namespace std;

void Swap(int* numbers, int start, int end){
	int temp=numbers[start];
	numbers[start]=numbers[end];
	numbers[end]=temp;
}

long long CountInverse(int* numbers, int startIndex, int endIndex, int number){
	for (int i=startIndex; i<=endIndex; ++i) {
		int firstNumber=numbers[i];
		if(firstNumber>number){
			return (endIndex-i+1);
		}
	}
	return 0;
}

long long CrossInvesePairs(int* numbers, int firstStartIndex, int firstEndIndex, int secondStartIndex, int secondEndIndex){
	long long inverseCount=0;
	for (int i=secondStartIndex; i<=secondEndIndex; ++i) {
		int secondNumber=numbers[i];
		inverseCount+=CountInverse(numbers,firstStartIndex,firstEndIndex, secondNumber);
	}
	return inverseCount;
}

void Merge(int* numbers,int firstStartIndex, int firstEndIndex, int secondStartIndex, int secondEndIndex ){
	//cout<<firstStartIndex<<endl;
	//cout<<secondEndIndex<<endl;
	int* temp=new int[secondEndIndex-firstStartIndex+1];
	int tempIndex=0;
	int* p1=numbers+firstStartIndex; int* p1End=numbers+firstEndIndex+1;
	int* p2=numbers+secondStartIndex; int* p2End=numbers+secondEndIndex+1;
	while (p1!=p1End && p2!=p2End) {
		if(*p1<*p2){
			temp[tempIndex++]=*p1;
			++p1;
		}
		else {
			temp[tempIndex++]=*p2;
			++p2;			
		}
	}
	if(p1==p1End){
		while (p2!=p2End) {
			temp[tempIndex++]=*p2;
			++p2;			
		}
	}
	else {
		while (p1!=p1End) {
			temp[tempIndex++]=*p1;
			++p1;
		}
	}
	assert(tempIndex==(secondEndIndex-firstStartIndex+1));
	for (int i=firstStartIndex; i<=secondEndIndex;++i) {
		numbers[i]=temp[i-firstStartIndex];
	}	
	delete[] temp;
}

long long SortCountInvesePairs(int* numbers, int start, int end){
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
	long long firstHalf=SortCountInvesePairs(numbers, start, middle);
	long long secondHalf=SortCountInvesePairs(numbers, middle+1, end);
	long long cross=CrossInvesePairs(numbers, start, middle, middle+1, end);
	Merge(numbers, start, middle, middle+1, end);
	return firstHalf+secondHalf+cross;
}


long long CountInvesePairs(int* numbers, int n){
	return SortCountInvesePairs(numbers, 0, n-1);
}


int main(int argc, char *argv[]) {
	ifstream fin("/Users/jianweisun/Dropbox/IntegerArray.txt");
	string line;
	vector<int> v;
	while (getline(fin, line)) {
		v.push_back(atoi(line.c_str()));
	}
	cout<<v.size()<<endl;
	cout<<CountInvesePairs(&v[0], v.size());
	//int e[]={3, 7, 10, 14, 18,19, 2,11,16, 17, 23, 25 };
	//assert(13==CountInvesePairs(e,12));
}