#include <iostream>
#include <stack>
#include <cassert>

using namespace std;

bool isValid(string s) {
   // Start typing your Java solution below
   // DO NOT write main() function
   	stack<char> parentheseStack;
	int length=s.size();
	for (int i=0; i<length; ++i) {
		char c=s[i];
		if('('==c||'{'==c||'['==c){
			parentheseStack.push(c);
		}
		else if (')'==c) {
			if(parentheseStack.empty()) return false;
			char top=parentheseStack.top();
			if('('!=top)
				return false;
			parentheseStack.pop();	
		}
		else if ('}'==c) {
			if(parentheseStack.empty()) return false;
			char top=parentheseStack.top();
			if('{'!=top)
					return false;
			parentheseStack.pop();	
		}
		else if (']'==c) {
			if(parentheseStack.empty()) return false;
			char top=parentheseStack.top();
			if('['!=top)
					return false;
			parentheseStack.pop();
		}
		else {
			return false;
		}
	}
	return  parentheseStack.empty(); 
}

int main(int argc, char *argv[]) {
	assert(false==isValid("["));
	assert(true==isValid("()"));
	assert(true==isValid(""));
	assert(true==isValid("([])"));
	assert(true==isValid("()[]"));
	assert(false==isValid(")([]"));
}