//http://codercareer.blogspot.com/2011/09/no-04-paths-with-specified-sum-in.html
//Question: All nodes along children pointers from root to leaf nodes form a path in a binary tree. Given a binary tree and a number, please print out all of paths where the sum of all nodes value is same as the given number. 
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
	
	static void PrintStack(Stack<TreeNode> stack){
		Console.WriteLine("stack end find, print");
	}
	
	static void PrintPathWithSum(TreeNode root, Stack<TreeNode> stack, int sum, int value){
		sum += root.value;
		stack.Push(root);
		if(root.left!=null || root.right!=null){
			
			PrintPathWithSum(root.left, stack, sum, value);			TreeNode leftPop=stack.Pop();
			sum -= leftPop.value;
			PrintPathWithSum(root.right, stack, sum, value);
			TreeNode rightPop= stack.Pop();
			sum -= rightPop.value;
		}
		else {//get to the leaf node
			Console.WriteLine(sum);
			if(sum==value){//print out the stack
				PrintStack(stack);
			}
		}
	} 
				
	static void Main(){
		Console.WriteLine("Print Path with specific sum");
		TreeNode root=CreateTestTree();
		Stack<TreeNode> stack=new Stack<TreeNode>();
		int sum=0;
		PrintPathWithSum(root, stack, sum, 22);
	}
}