using System;
using System.Collections.Generic;
using System.Diagnostics;

//use two stack to simulate a queue.
class QueueWithTwoStack
{
	private Stack<int> _stackOne=new Stack<int>();
	private Stack<int> _stackTwo=new Stack<int>();
	
	public void Enqueue(int value){
		_stackOne.Push(value);
	}
	
	public int Dequeue(){
		if(_stackTwo.Count==0){
			while(_stackOne.Count>0){
				int topValue=_stackOne.Pop();
				_stackTwo.Push(topValue);
			}
		}
		return _stackTwo.Pop();
	}	
}

class QueueWithTwoStackTest{
		
	static void Main(){
		Console.WriteLine("Simulate Queue With Two Stacks");
		int[] a={1,2,3,4,5};
		QueueWithTwoStack queueWithTwoStack=new QueueWithTwoStack();
		for (int i=0; i<a.Length; i++) {
			queueWithTwoStack.Enqueue(i);
		}
		Debug.Assert(1==queueWithTwoStack.Dequeue());
		Debug.Assert(2==queueWithTwoStack.Dequeue());
		Debug.Assert(3==queueWithTwoStack.Dequeue());
		Debug.Assert(4==queueWithTwoStack.Dequeue());
		Debug.Assert(5==queueWithTwoStack.Dequeue());
	}
}