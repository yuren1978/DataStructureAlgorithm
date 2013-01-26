#include <iostream>
#include <algorithm>
#include <vector>
#include <cassert>

using namespace std;

 void copy(vector<int> &numbers, int* copyArray, int size) {
	 for (int i=0; i<size; ++i) {
		copyArray[i]=numbers[i];		
	}
 }

int FindPosition(int* copyArray, int size, int number){
	for (int i=0; i<size; ++i) {
		if(number==copyArray[i]){
			return i;
		}
	}
	return -1;
}

 vector<int> twoSum(vector<int> &numbers, int target) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
		 
		vector<int> indexes;
		int start=0;
		int size=numbers.size();
		int end=size-1;
		int* copyArray=new int[size];
		copy(numbers, copyArray, size);
		sort(numbers.begin(), numbers.end());
       
		 while (start<end) {
			if(numbers[start]+numbers[end]<target){
				++start;
			}
			else if (numbers[start]+numbers[end]>target) {
				--end;
			}
			else {//target find
				int position1=FindPosition(copyArray, size, numbers[start]);
				int position2=FindPosition(copyArray, size, numbers[end]);
				assert(position1>=0);
				assert(position2>=0);
				if(position1<position2){
					indexes.push_back(position1+1);					indexes.push_back(position2+1);
				}
				else {
					indexes.push_back(position2+1);					indexes.push_back(position1+1);
				}
				break;
			}
		}
		delete[] copyArray;
		return indexes;
    }

int main(int argc, char *argv[]) {
	
}