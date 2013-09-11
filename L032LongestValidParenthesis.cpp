//http://www.mitbbs.com/article_t/JobHunting/32185871.html
//Given a string containing just the characters '(' and ')', find the length of the longest valid (well-formed) parentheses substring.
//For "(()", the longest valid parentheses substring is "()", which has length = 2.
//Another example is ")()())", where the longest valid parentheses substring is "()()", which has length = 4.
#include <algorithm>
#include <iostream>
#include <stack>
#include <cassert>
#include <utility>

using namespace std;

int longestValidParentheses(string s) {
    // Start typing your C/C++ solution below
    // DO NOT write int main() function
   	std::stack<int > lefts;
	int maxLength=0;
	int stringLength=s.size();
	int currentStart=-1;
	for (int i=0; i<stringLength; ++i) {
		char c=s[i];
		if('('==c){
			lefts.push(i);
		}
		else {//starts with ')'
			if(lefts.empty()){
				currentStart=i;		
			}
			else {
				lefts.pop();
				if(lefts.empty()){
					cout<<"stack empty"<<endl;
					maxLength=	max(maxLength, i-currentStart);
				}
				else {
					cout<<"stack empty"<<endl;
					maxLength=	max(maxLength, i-lefts.top());					
				}			
			
			}		
		}
	}
	return maxLength;
}

int main(int argc, char *argv[]) {
	assert(4==longestValidParentheses("()()"));
}