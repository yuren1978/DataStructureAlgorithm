using System;
using System.Collections.Generic;

public class Node{
	public int value {get;set;}
	public Node left {get;set;}
	public Node right {get;set;}
}

class PreOrderNonRecursive{

	static Node CreateTreeFromArray(int[] a, int start, int end){
		if(start<=end){
			int middle=(start+end)/2;
			Node node=new Node {value=a[middle], left=null, right=null};
			node.left=CreateTreeFromArray(a, start, middle-1);
			node.right=CreateTreeFromArray(a, middle+1, end);
			return node;
		}
		else{
			return null;
		}
	}

	static void Travel(Node root){
		if(root==null)
			return;
		Node current=root; 	
		Stack<Node> _stack=new Stack<Node>();
		while(current!=null || _stack.Count>0){
			if(current!=null){
				Console.Write(current.value+" ");
				if(current.right!=null){
					_stack.Push(current.right);
				}
				current=current.left;
			}
			else{
				current=_stack.Pop();	
			}
		}

	}

	static void Main(){
		int[] a={1,2,3};
		Node root=CreateTreeFromArray(a,0, 2);
		Travel(root);
	}
}