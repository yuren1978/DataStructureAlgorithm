#include <iostream>
#include <fstream>
#include <cassert>
#include <vector>

using namespace std;



void Exchange(int*number, int i, int j){
	if(i!=j){
		int temp=number[i];
		number[i]=number[j];
		number[j]=temp;		
	}
} 


int PartitionFirst(int* number, int start, int end){
	int pivotNumber=number[start];
	int i=start+1;
	
	for(int j=start+1; j<=end; ++j) {
		if(number[j]<pivotNumber){
			Exchange(number, i, j);
			i++;		
		}
	}
	Exchange(number, start, i-1);
	return i-1;
}

bool Between(int number, int bound1, int bound2){
	return (number>=bound1 && number <=bound2)
		|| (number>=bound2 && number <=bound1);
}

int FindMedianOfThree(int* number, int start, int end){
	int middle=(start+end)/2;
	if(Between(number[start], number[middle], number[end])){
		return start;
	}
	else if (Between(number[middle], number[start], number[end])) {
		return middle;
	}
	return end;
}

void QuickSort(int* number, int start, int end, long long& count){
	if(end-start<1){
		return;
	}	
	count+=(end-start);
	//int pivotIndex=FindMedianOfThree(number, start, end);
	Exchange(number, start, end);
	int partitionIndex=PartitionFirst(number, start, end);
	QuickSort(number, start, partitionIndex-1, count);
	QuickSort(number, partitionIndex+1, end, count);	
}

int main(int argc, char *argv[]) {
	ifstream fin("/Users/jianweisun/Dropbox/QuickSort.txt");
	string line;
	vector<int> v;
	while (getline(fin, line)) {
		v.push_back(atoi(line.c_str()));
	}
	int size=v.size();
	long long count=0;
	QuickSort(&v[0], 0, size-1, count);
	cout<<count<<endl;
	for (int i=0; i<size-1; ++i) {
		assert(v[i]<=v[i+1]);
	}
}