#include <iostream>
#include <cassert>

using namespace std;

int lengthOfLastWord(const char *s) {
      // Start typing your C/C++ solution below
      // DO NOT write int main() function
	if(s==NULL)
		return 0;
     int lengthOfString=strlen(s);
	 const char* pLast=s+lengthOfString-1; //jump to the end of string
	 
	int lengthOfSpace=0;
	 while (*pLast==' ' && lengthOfSpace<lengthOfString) {
		pLast--;
		lengthOfSpace++;
	} 
	
	if(lengthOfSpace==lengthOfString)
		return 0;
	
	 int lengthOfWord=0;
	 while (*pLast!=' ' && lengthOfWord<lengthOfString) {
		pLast--;
		lengthOfWord++;
	} 	  
	return lengthOfWord;
}

int main(int argc, char *argv[]) {
	const char s[]="H";
	assert(1==lengthOfLastWord(s));
}