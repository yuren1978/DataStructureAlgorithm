//http://stackoverflow.com/questions/3172179/valid-permutation-of-parenthesis
//https://docs.google.com/spreadsheet/pub?key=0AqHq2JLBVNBwdHJkVEFuRWExT2owWGNKOXM4WnpQZEE&single=true&gid=0&output=html

#include <iostream>
#include <vector>
#include <string>
#include <cassert>

using namespace std;

void generateParenthesis(int startStock, int endStock, string s,  vector<string>& vectors){
	if(startStock==0 && endStock==0){
		vectors.push_back(s);
		return;
	}
	if(startStock>0){
		generateParenthesis(startStock-1,endStock+1, s+"(", vectors);
	}
	if(endStock>0){
		generateParenthesis(startStock,endStock-1, s+")", vectors);
	}
} 

vector<string> generateParenthesis(int n) {
    // Start typing your C/C++ solution below
    // DO NOT write int main() function
	vector<string> stringVectors;
	generateParenthesis(n, 0, "", stringVectors);
	assert(5==stringVectors.size());
	return 	 stringVectors;       
}

int main(int argc, char *argv[]) {
	generateParenthesis(3);
}