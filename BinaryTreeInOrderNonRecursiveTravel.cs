using System;
using System.Collections.Generic;

public class TreeNode{
	public int value {get;set;}
	public TreeNode left {get;set;}
	public TreeNode right {get;set;}
}

public class BinaryTreeInOrderNonRecrusiveTravel{

	static TreeNode CreateTreeFromArray(int[] a, int start, int end){
		if(start<=end){
			int middle=(start+end)/2;
			TreeNode treeNode=new TreeNode(){value=a[middle], left=null, right=null};
			treeNode.left=CreateTreeFromArray(a, start, middle-1);
			treeNode.right=CreateTreeFromArray(a, middle+1, end);
			return treeNode;
		}
		else{
			return null;
		}
	}

	static void InOrderNonRecursiveTravel(TreeNode root){
		Stack<TreeNode> stack=new Stack<TreeNode>();
		TreeNode node=root;
		while(node!=null||stack.Count>0){
			if(node!=null){
				stack.Push(node);
				node=node.left;
			}
			else{
				node=stack.Pop();
				Console.Write(node.value+" ");
				node=node.right;
			}
		}	
	}

	static void Main(){
		Console.WriteLine("test");
		int[] a={1,2,3,4,5,6,7,8,9,10};
		TreeNode root=CreateTreeFromArray(a, 0, a.Length-1);
		InOrderNonRecursiveTravel(root);
	}
}