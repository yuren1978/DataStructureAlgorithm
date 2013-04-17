#include <iostream>
#include <vector>
#include <map>

using namespace std;


void letterCombine(string digits, vector<string>& stringCombinations, int currentIndex, string s){
	map<char, string> lookup;
	lookup['1']="";
	lookup['2']="abc";
	lookup['3']="def";
	lookup['4']="ghi";
	lookup['5']="jkl";
	lookup['6']="mno";
	lookup['7']="pqrs";
	lookup['8']="tuv";
	lookup['9']="wxyz";
	if(s.size()==digits.size()){
		stringCombinations.push_back(s);
		return;
	}
	char c=digits[currentIndex];
	string mappedString=lookup[c];
	for(int i=0; i<mappedString.size();++i){
		string copyOfs(s);
		copyOfs.push_back(mappedString[i]);
		letterCombine(digits,stringCombinations, currentIndex+1, copyOfs);
	}
}

vector<string> letterCombinations(string digits) {
    // Start typing your C/C++ solution below
    // DO NOT write int main() function
	string s;
    vector<string> stringCombinations;
	letterCombine(digits, stringCombinations, 0,  s);	
	return  stringCombinations;   
}

int main(int argc, char *argv[]) {
	
}