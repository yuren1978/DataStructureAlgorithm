using System;
using System.Collections.Generic;

namespace TwoStackFindMin
{
	class MainClass
	{
		
		//Design a stack that supports push, pop, and retrieving the minimum element in constant time. Can you do this
		//Today, I read this interesting problem (exercise 4-44) from the excellent book "The Algorithm Design Manual" by Steven Skiena. 
		//I also found that this question had been asked in Amazon and Bloomberg interviews.
		//http://www.ihas1337code.com/2010/11/stack-that-supports-push-pop-and-getmin.html
		//http://www.mitbbs.com/article_t/JobHunting/31758299.html
		public static void Main (string[] args)
		{
			//Console.WriteLine ("Hello World!");
			//Test empty case
			DoubleStack doubleStack=new DoubleStack();
			Console.WriteLine("min value is " +doubleStack.Pop());
			
			int[] a={1,5,3,2};
			for (int i = 0; i < a.Length; i++) {
				doubleStack.Push(a[i]);
			}
			
			Console.WriteLine("min value is " + doubleStack.FindMin());
			
			doubleStack.Push(1);
			
			Console.WriteLine("min value is " + doubleStack.FindMin());
			doubleStack.Pop();
			Console.WriteLine("min value is " + doubleStack.FindMin());
		}
		
	}
	
	class DoubleStack
	{
		public int INVALIDVALUE=Int32.MaxValue;
		Stack<int> _minStack=new Stack<int>();
		Stack<int> _normalStack=new Stack<int>();
		
		public void Push(int value)
		{
			_normalStack.Push(value);
			if(_minStack.Count==0||_minStack.Peek()>=value)
				_minStack.Push(value);
			}
		
		
			public int Pop()
			{
				if(_normalStack.Count==0) return INVALIDVALUE;
				if(_minStack.Peek()==_normalStack.Peek())
					_minStack.Pop();
				return _normalStack.Pop();
			}
		
			public int FindMin()
			{
				if(_minStack.Count==0) return INVALIDVALUE;
				else {
					return _minStack.Peek();
				}
			}

		}
	
		

}


