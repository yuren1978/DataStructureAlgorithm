//http://codercareer.blogspot.com/2011/09/no-04-paths-with-specified-sum-in.html
//Question: All nodes along children pointers from root to leaf nodes form a path in a binary tree. Given a binary tree and a number, 
//please print out all of paths where the sum of all nodes value is same as the given number. 


using System;
using System.Collections.Generic;


class PathWithSpecificSum{
	
	class TreeNode{
		public int value {get;set;}
		public TreeNode left {get;set;} 
		public TreeNode right {get;set;}
	}
	
	static TreeNode CreateTestTree(){
		TreeNode root=new TreeNode { value=10 };
		root.left=new TreeNode {value=5 };
		root.left.left= new TreeNode { value=4, left=null, right=null };
		root.left.right=new TreeNode { value=7, left=null, right=null };
		root.right=new TreeNode {value=12, left=null, right=null };
		return root;
	}
	
	static void PrintStack(Stack<int> stack){
		Console.WriteLine("stack end find, print");
		int[] array=stack.ToArray();
		for (int i=0; i<array.Length; i++)
		{
			Console.Write(array[i]+" ");
		}
		Console.WriteLine();
	}
	
	static void PrintPathWithSum(TreeNode root, Stack<int> stack, int sum, int value){
		if(root!=null){
			sum+=root.value;
			//Console.WriteLine("Push Value "+root.value);
			stack.Push(root.value);
			if(sum==value){
				PrintStack(stack);
			}
		}
		
		if(root.left!=null)
			PrintPathWithSum(root.left, stack, sum, value);
		if(root.right!=null)	
			PrintPathWithSum(root.right,stack, sum, value);
				
		int topValue=stack.Pop();
		//Console.WriteLine("Pop Value "+topValue);
		sum-=topValue;
	} 
				
	static void Main(){
		TreeNode root=CreateTestTree();
		Stack<int> stack=new Stack<int>();
		int sum=0;
		PrintPathWithSum(root, stack, sum, 22);
	}
}