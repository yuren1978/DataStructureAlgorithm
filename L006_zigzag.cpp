#include <iostream>
//PAYPALISHIRING to PAHNAPLSIIGYIR

using namespace std;

void CopyStringToArray(string s, int size, char* array, int startIndex, int step, int& newIndex){
	for (int i=startIndex; i<size; i=i+step) {
		array[++newIndex]=s[i];
	}
}

string convert(string s, int nRows) {
    // Start typing your C/C++ solution below
    // DO NOT write int main() function    
   int size=s.size();
   char* array=new char[size+1];
	int startIndex=0;
	int newIndex=0;
	for (int i=nRows; i>=1; --i) {
		CopyStringToArray(s, size, array, startIndex, i, newIndex);
		startIndex++;
	}	
	assert(size==newIndex);
	array[size]='\0';
	string s(array);
	return 2;     
}

int main(int argc, char *argv[]) {
	
}