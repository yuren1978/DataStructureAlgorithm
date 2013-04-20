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
        map<int, int> numberIndexHash;
        int size=numbers.size();
        for(int i=0; i<size; ++i){
            if(numberIndexHash.find(numbers[i])==numberIndexHash.end()){
                numberIndexHash[target-numbers[i]]= i ;
            }
            else{
                int currentIndex=i;
                int otherIndex=numberIndexHash[numbers[i]];
                if(currentIndex<otherIndex){
                    indexes.push_back(currentIndex+1);
                    indexes.push_back(otherIndex+1);
                }
                else{
                    indexes.push_back(otherIndex+1);
                    indexes.push_back(currentIndex+1);
                }
            }
        }
        return indexes;
    }

int main(int argc, char *argv[]) {
	
}