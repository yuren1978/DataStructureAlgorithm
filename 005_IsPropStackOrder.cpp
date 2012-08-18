//haotao book Q 22: Page 136
//http://codercareer.blogspot.com/2011/11/no-21-push-and-pop-sequences-of-stacks.html
#include <cstdio>
#include <cstdlib>
#include <cassert>
#include <stack>
#include <iostream>

using namespace std;

	bool IsPopOrder(const int* push, const int* pop, int nLength)
	{
		bool isProperOrder=false;
		const int* currentPush=push;
		const int* currentPop=pop;
		stack<int> pushStack;
		//cout<<"start";
		while (currentPush-push<nLength ) {
			if(pushStack.size()==0 || pushStack.top()!=*currentPop){
				//cout<<"push";
				pushStack.push(*currentPush);				++currentPush;			
			} 
			
			while(pushStack.size()>0 && pushStack.top()==*currentPop && currentPop-pop<nLength){
				pushStack.pop();
				++currentPop;
			}
		}
		
		if(pushStack.size()==0)	
			isProperOrder=true;
		
		return isProperOrder;
	}

	
	int main(int argc, char *argv[]) {
		int push[]={1, 2, 3, 4, 5};
		int pop1[]={1, 2, 3, 4, 5};
		int pop2[]={4, 5, 3, 2, 1};
		int pop3[]={4, 3, 5, 1, 2};
		assert(IsPopOrder(push, pop1, 5));
		assert(IsPopOrder(push, pop2, 5));
		assert(false==IsPopOrder(push, pop3, 5));
	}
