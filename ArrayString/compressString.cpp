#include <iostream>
#include <string>
#include <cassert>

using namespace std;

string compressString(string input){
	int size=input.size();
	if(size<=1) return input;

	string compressString;
	char currentChar=input[0];
	int i=1;
	int count=1;
	while(i<size){
		if(currentChar==input[i]){
			count++;
		}
		else{
			compressString.append(1, currentChar);
			compressString.append(1, '0'+count);
			currentChar=input[i]; //update
			count=1;
		}
		i++;
	}
	compressString.append(1, currentChar);
	compressString.append(1, '0'+count);
	return compressString;
}

int main(int argc, char const *argv[])
{
	assert("a2b1c5a3"==compressString("aabcccccaaa"));
	assert("a2b1"==compressString("aab"));

	return 0;
}