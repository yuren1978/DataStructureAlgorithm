#include <cstdio>
#include <ctype.h>
#include <cassert>
#include <string>

#include <iostream>

using namespace std;
//Given a string, determine if it is a palindrome, considering only alphanumeric characters and ignoring cases.

//For example,
//"A man, a plan, a canal: Panama" is a palindrome.
//"race a car" is not a palindrome.

    bool isPalindrome(string s) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
		if(s.length()==0)
			return true;
		int start=0;
		int end=s.length()-1;
		while (start<end) {
			while(!isalnum(s[start]) && start<end)	 			++start;
			while(!isalnum(s[end]) && start<end)				--end;
			if(tolower(s[start]) !=tolower(s[end])){
				return false;
			}
			++start;
			--end;
		}
		return true;        
    }


int main(int argc, char *argv[]) {
	cout<<"Test Palindrome"<<endl;
	assert(isPalindrome(".,"));
	assert(isPalindrome("A man, a plan, a canal: Panama"));
	//assert(!isPalindrome("race a car"));
}


