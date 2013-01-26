#include <iostream>
#include <map>
#include <vector>
#include <cassert>


using namespace std;

	void LetterCombinationRecursive(int index, string s,  map<char,string>& digitToChar, string digits, int lengthOfDigit, vector<string>& vectors){
		if(index==lengthOfDigit){
			vectors.push_back(s);
			return;
		}
		
		string mappedString=digitToChar[digits[index]];
		int mappedStringLength=mappedString.size();
		
		for (int i=0; i<mappedStringLength; ++i) {
			s.push_back(mappedString[i]);
			LetterCombinationRecursive(index+1, s ,digitToChar,  digits,  lengthOfDigit, vectors) ;
			s.resize (s.size () - 1);
		}
	}


   vector<string> letterCombinations(string digits) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
		vector<string> vectors;	
		map<char,string> digitToChar;
		digitToChar['2']="abc";
		digitToChar['3']="def";
		digitToChar['4']="ghi";
		digitToChar['5']="jkl";
		digitToChar['6']="mno";
		digitToChar['7']="pqrs";
		digitToChar['8']="tuv";
		digitToChar['9']="wxyz";
		
		int lengthOfDigit=digits.size();
		LetterCombinationRecursive(0, "", digitToChar, digits, lengthOfDigit, vectors);
		return vectors;
    }

int main(int argc, char *argv[]) {
	vector<string> vectors=letterCombinations("234");
	assert(27==vectors.size());
}