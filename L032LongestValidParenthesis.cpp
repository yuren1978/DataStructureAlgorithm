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
   	std::stack<pair<char,int> > parenStack;
	int maxLength=0;
	int stringLength=s.size();
	int currentStart=0;
	for (int i=0; i<stringLength; ++i) {
		char c=s[i];
		if('('==c){
			parenStack.push(make_pair(c,i));
		}
		else {//starts with ')'
			if(parenStack.empty()){
				currentStart=i+1;		
			}
			else {
				pair<char,int> topOfStack=parenStack.top();
				parenStack.pop();
				if('('==topOfStack.first){//match found
					if(parenStack.empty()){
						maxLength=	max(maxLength, i-currentStart+1);
					}
					else {
						maxLength=	max(maxLength, i-parenStack.top().second);					
					}			
				}
			}		
		}
	}
	return maxLength;
}

int main(int argc, char *argv[]) {
	assert(4==longestValidParentheses("((())"));
}