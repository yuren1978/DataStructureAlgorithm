#include <iostream>
#include <cassert>

using namespace std;

string expanding(string s, int start, int end, int size){
	while (start>=0 && end<=size-1 && s[start]==s[end] ) {
			start--;
			end++;
		}
	return s.substr(start+1, end-start-1);
}

string expandingEven(string s, int position, int size){
	int start=position-1;
	int end=position;
	return expanding(s, start, end, size);
}

string expandingOdd(string s, int position, int size){
	int start=position-1;
	int end=position+1;
	return expanding(s, start, end, size);
}


string longestPalindrome(string s) {
    // Start typing your C/C++ solution below
    // DO NOT write int main() function
	int size=s.size();
	if(size<=1){
		return s;
	}
	string maxString=s.substr(0,1);
	for (int i=1; i<size; ++i) {
		string evenString=expandingEven(s,i,size);
		if(evenString.size()>maxString.size()){
			maxString=evenString;
		}
		string oddString=expandingOdd(s,i, size);
		if(oddString.size()>maxString.size()){
			maxString=oddString;
		}
	}
	return maxString;        
}

int main(int argc, char *argv[]) {
	assert(longestPalindrome("a") == "a");
	assert(longestPalindrome("sa") == "s");
	assert(longestPalindrome("aa") == "aa");
	assert(longestPalindrome("aaa") == "aaa");
	assert(longestPalindrome("aba") == "aba");
	assert(longestPalindrome("abba") == "abba");
	assert(longestPalindrome("aaaa") == "aaaa");
	assert(longestPalindrome("aaaaa") == "aaaaa");
	assert(longestPalindrome("aabaa") == "aabaa");
	assert(longestPalindrome("sambasiva") == "s");
	assert(longestPalindrome("sambabmiv") == "mbabm");
	assert(longestPalindrome("saaasr") == "saaas");
	assert(longestPalindrome("saasr") == "saas");
}