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
		return true;	
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
