//http://stackoverflow.com/questions/3172179/valid-permutation-of-parenthesis
//https://docs.google.com/spreadsheet/pub?key=0AqHq2JLBVNBwdHJkVEFuRWExT2owWGNKOXM4WnpQZEE&single=true&gid=0&output=html


//Essentially we keep track of how many open and close parentheses are "on stock" for us to use as we're building the string recursively.

//If there's nothing on stock, the string is fully built and you can just print it out
//If there's an open parenthesis available on stock, try and add it on.
//Now you have one less open parenthesis, but one more close parenthesis to balance it out
//If there's a close parenthesis available on stock, try and add it on.
//Now you have one less close parenthesis


#include <iostream>
#include <vector>
#include <string>
#include <cassert>

using namespace std;

void generateParenthesis(int startStock, int endStock, string s,  vector<string>& vectors){
	if(startStock==0 && endStock==0){
		//cout<<"complet string : "+ s<<endl;
		vectors.push_back(s);
		return;
	}
	if(startStock>0){
		//cout<<"left: "+ s+"("<<endl;
		generateParenthesis(startStock-1,endStock+1, s+"(", vectors);
	}
	if(endStock>0){
		//cout<<"right: "+s+")"<<endl;
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