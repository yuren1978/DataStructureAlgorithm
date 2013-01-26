//http://www.leetcode.com/2011/05/longest-substring-without-repeating-characters.html
//Given a string, find the length of the longest substring without repeating characters. For example, the longest substring without repeating letters for “abcabcbb” is “abc”, which the length is 3. For “bbbbb” the longest substring is “b”, with the length of 1.

#include <cstdio>
#include <string>
#include <cassert>

using namespace std;

int positionAtEarlierPartString(string s, char findingChar, int start, int end){
	for (int i=start; i<end; i++) {
		if(s[i]==findingChar){
			return i;
		}
	}
	return -1;
}

int lengthOfLongestSubstring(string s) {
   // Start typing your C/C++ solution below
   // DO NOT write int main() function
	int longestLength=0;
	int start=0;
    size_t length=s.size();
	if(length==1)
		return 1;
	for (int i=1; i<length; i++) {
		char currentChar=s[i];
		int dupPosition=positionAtEarlierPartString(s, currentChar, start, i);
		if(dupPosition>=0){
			if((i-start)>longestLength){
				longestLength=i-start;
			}
			start=dupPosition+1;
		}
	} 
	return longestLength;    
}

int main(int argc, char *argv[]) {
	assert(1==lengthOfLongestSubstring("bbbbb"));
	assert(3==lengthOfLongestSubstring("abcabcbb"));
}