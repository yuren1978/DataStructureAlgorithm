//http://www.mitbbs.com/article_t/JobHunting/32185871.html
//Given a string containing just the characters '(' and ')', find the length of the longest valid (well-formed) parentheses substring.
//For "(()", the longest valid parentheses substring is "()", which has length = 2.
//Another example is ")()())", where the longest valid parentheses substring is "()()", which has length = 4.

//从左到右扫一边，再从右到左扫一边，O（n） time O(1) space

#include <iostream>
#include <stack>
#include <cassert>

using namespace std;

int longestValidParentheses(string s) {
    // Start typing your C/C++ solution below
    // DO NOT write int main() function
    const char* p=s.c_str();
	const char* pStart=p;
	int maxLength=0;
	stack<const char*> pointerStack;
	while (*p!='\0') {
		if(*p=='('){
			pointerStack.push(p);
		}
		else {
			if(!pointerStack.empty() && *pointerStack.top()=='('){
				pointerStack.pop();	
				int currentLength=pointerStack.empty()?p-pStart+1:p-pointerStack.top();
				if(currentLength>maxLength){
					maxLength=currentLength;
				}
					
			}
			else {
				pointerStack.push(p);	
			}
		}
		p++;
	}    
	return maxLength;
}

int main(int argc, char *argv[]) {
	assert(0==longestValidParentheses(")"))	;
}