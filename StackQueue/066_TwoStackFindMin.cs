using System;
using System.Collections.Generic;


//Design a stack that supports push, pop, and retrieving the minimum element in constant time. Can you do this
//Today, I read this interesting problem (exercise 4-44) from the excellent book "The Algorithm Design Manual" by Steven Skiena. 
//I also found that this question had been asked in Amazon and Bloomberg interviews.
//http://www.ihas1337code.com/2010/11/stack-that-supports-push-pop-and-getmin.html
//http://www.mitbbs.com/article_t/JobHunting/31758299.html

public class DoubleStack 
{
	private int _minValue=Int32.MaxValue;
	private Stack<int> _normalStack=new Stack<int>();
	private Stack<int> _minStack=new Stack<int>();

	public void Push(int value){
		_normalStack.Push(value);
		if(value<_minValue)
		{
			_minStack.Push(value);
			_minValue=value;	
		}	
	}

	public int Pop(){
		if(_normalStack.Count==0) return Int32.MaxValue;
		if(_normalStack.Peek()==_minStack.Peek())
		{
			return _minStack.Pop();	
		}
		return _normalStack.Pop();
	}

	public int GetMin(){
		return _minStack.Peek();
	}
}

class TwoStackFindMin
{
	public static void Main()
	{
		Console.WriteLine("Using Two stack find min");
		DoubleStack doubleStack=new DoubleStack();
		int[] a={1,2,3,4,5};
		for(int index=0;index<a.Length;index++){
			doubleStack.Push(a[index]);	
		}
		Console.WriteLine("Min Value is {0}", doubleStack.GetMin());
		Console.WriteLine("Pop Value is {0}", doubleStack.Pop());
		Console.WriteLine("Min Value is {0}", doubleStack.GetMin());
	}

}