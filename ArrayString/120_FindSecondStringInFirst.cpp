#include <iostream>
#include <cstdio>
#include <cassert>
#include <string>
using namespace std;

void FindSecondInFirstRecursive(int& count, string first, int firstPosition, string second, int secondPosition){
	int secondSize=second.size();
	int firstSize=first.size();
	if(secondPosition ==secondSize ){//reach the end
		if(firstPosition<=firstSize){//first one not reach the end yets
			count++;
		}
		return;
	}
	else {
			char secondChar=second[secondPosition];
			for (int j=firstPosition; j<firstSize; j++) {
				char firstChar=first[j];
				if(secondChar==firstChar){
					FindSecondInFirstRecursive(count, first, j+1, second, secondPosition+1);	
				}
			}
	}	
}


int FindSecondInFirst(string first, string second){
	int count=0;
	int firstPosition=0;
	int secondPosition=0;
	FindSecondInFirstRecursive(count, first, firstPosition, second, secondPosition);
	return count;
}




int main(int argc, char *argv[]) {
	assert(1==FindSecondInFirst("a","a"));
	assert(2==FindSecondInFirst("aa","a"));
	assert(1==FindSecondInFirst("ba","a"));
	assert(1==FindSecondInFirst("ba","b"));
	assert(1==FindSecondInFirst("ba","ba"));
	assert(0==FindSecondInFirst("a","ab"));

}



