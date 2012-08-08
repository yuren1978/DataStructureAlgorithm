//haotao book Q 22: Page 136
//http://codercareer.blogspot.com/2011/11/no-21-push-and-pop-sequences-of-stacks.html
#include <cstdio>
#include <cstdlib>
#include <cassert>
#include <stack>



	bool IsPopOrder(const int* pPush, const int* pPop, int nLength)
	{
	    bool bPossible = false;

	    if(pPush != NULL && pPop != NULL && nLength > 0)
	    {
	        const int* pNextPush = pPush;
	        const int* pNextPop = pPop;

	        std::stack<int> stackData;

	        while(pNextPop - pPop < nLength)
	        {
	            // When the number to be popped is not on top of stack,
	            // push some numbers in the push sequence into stack
	            while(stackData.empty() || stackData.top() != *pNextPop)
	            {
	                // If all numbers have been pushed, break
	                if(pNextPush - pPush == nLength)
	                    break;

	                stackData.push(*pNextPush);

	                pNextPush ++;
	            }

	            if(stackData.top() != *pNextPop)
	                break;

	            stackData.pop();
	            pNextPop ++;
	        }

	        if(stackData.empty() && pNextPop - pPop == nLength)
	            bPossible = true;
	    }

	    return bPossible;
	}

	
	int main(int argc, char *argv[]) {
		int push[]={1, 2, 3, 4, 5};
		int pop[]={1, 2, 3, 4, 5};
		assert(IsPopOrder(push, pop, 5));
	}
