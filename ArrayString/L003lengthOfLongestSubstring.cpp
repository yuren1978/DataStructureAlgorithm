#include <iostream>
#include <cassert>
#include <map>

using namespace std;

//Given a string, find the length of the longest substring without repeating characters. For example, the longest substring without repeating letters for "abcabcbb" is "abc", which the length is 3. For "bbbbb" the longest substring is "b", with the length of 1.


int GetCurrentMaxLength(string s, int& startPosition){
	int length=0;
	int size=s.size();
	map<char, int> lookup;
	for (int i=startPosition; i<size; ++i) {
		char c=s[i];
		if(lookup.find(c)==lookup.end()){
			++length;
			lookup.insert(std::pair<char, int>(c, i));
		}
		else {
			startPosition=lookup[c]+1;
			break;
		}
	}
	return length;
}

int lengthOfLongestSubstring(string s) {
   // Start typing your C/C++ solution below
   // DO NOT write int main() function
    int size=s.size();
	if(size<=1)
		return size;
	int maxLength=0;
	int position=0;
	while (position+maxLength<size) {
		int currentLength=GetCurrentMaxLength(s, position);
		//cout<<currentLength<<endl;
		if(currentLength>maxLength){
			maxLength=currentLength;
		}
	}
	return maxLength;	
}

int main(int argc, char *argv[]) {
		//"kitzyxacbh"
		cout<<lengthOfLongestSubstring("qpxrjxkitzyxacbhhkicqc")<<endl;
		assert(10==lengthOfLongestSubstring("qpxrjxkitzyxacbhhkicqc"));
}