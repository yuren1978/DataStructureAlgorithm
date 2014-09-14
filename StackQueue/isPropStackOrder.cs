using System;
using System.Collections.Generic;
using System.Diagnostics;

class Program
{
	private static bool IsPopOrder(int[] push, int[] pop, int length)
	{
		bool isPropOrder=false;
		Stack<int> stack=new Stack<int>();
		int pushIndex=0; int popIndex=0;
		while (pushIndex<length)
		{
			if(stack.Count==0||stack.Peek()!=pop[popIndex])
			{
				stack.Push(push[pushIndex]);				}
			while(stack.Count>0 && popIndex<length && stack.Peek()==pop[popIndex])
			{
				stack.Pop();
				++popIndex;	
			}			
			if(popIndex==length){
				isPropOrder=true;
				break;
			}
			++pushIndex;
		}
		
		return isPropOrder;
			
	}
	
	
	static void Main(string[] args)
	{
		int[] push={1, 2, 3, 4, 5};
		int[] pop1={1, 2, 3, 4, 5};
		int[] pop2={4, 5, 3, 2, 1};
		int[] pop3={4, 3, 5, 1, 2};
		Console.WriteLine(IsPopOrder(push, pop1, 5));
		Console.WriteLine(IsPopOrder(push, pop2, 5));
		Console.WriteLine(IsPopOrder(push, pop3, 5));
	}
}