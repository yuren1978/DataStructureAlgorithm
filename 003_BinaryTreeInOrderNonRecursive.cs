using System;
using System.Collections.Generic;

public class InOrderIterator{
	private Node _current;
	private Stack<Node> _stack=new Stack<Node>();
	public InOrderIterator(Node root){
		_current=root;
	}

	public bool HasNext(){
		return _current!=null || _stack.Count>0;
	}

	public Node Next(){
		while(_current!=null){
			_stack.Push(_current);
			_current=_current.left;
		}
		Node nodeToReturn=_stack.Pop();
		_current=_current.right;
		return nodeToReturn;
	}
}


public class Node{
	public int value {get;set;}
	public Node left {get;set;}
	public Node right {get;set;}
}

public class BinaryTreeInOrderNonRecursive{

	static Node CreateTreeFromArray(int[] a, int start, int end){
		if(start<=end){
			int middle=(start+end)/2;
			Node node=new Node { value=a[middle], left=null, right=null };	
			node.left=CreateTreeFromArray(a, start, middle-1);
			node.right=CreateTreeFromArray(a, middle+1, end);
			return node;
		}
		else{
			return null;
		}		
	}

	static void InOrderTravel(Node root){
		Stack<Node> stack=new Stack<Node>();
		Node current=root;
		while(current!=null||stack.Count>0){
			if(current!=null){
				stack.Push(current);
				current=current.left;
			}
			else{
				current=stack.Pop();
				Console.Write(current.value+"-");
				current=current.right;
			}	
		}
	}

	static void PreOrderRecursive(Node root){
		if(root!=null){
			Console.WriteLine(root.value+"#");
			PreOrderRecursive(root.left);
			PreOrderRecursive(root.right);
		}
	}

	static void PreOrderTravel(Node root){
		Stack<Node> stack=new Stack<Node>();
		Node current=root;
		stack.Push(current);
		while(stack.Count>0){
			current=stack.Pop();
			Console.Write(current.value+"-");
			if(current.right!=null)
				stack.Push(current.right);
			if(current.left!=null)
				stack.Push(current.left);	
		}
	}

	static void Main(){
		int[] a={1,2,3,4,5,6,7,8,9,10};
		Console.WriteLine("Binary Tree InOrder NonRecursive");
		Node root=CreateTreeFromArray(a, 0, a.Length-1);
		//InOrderTravel(root);
		//InOrderIterator inOrderIterator=new InOrderIterator(root);
		//while(inOrderIterator.HasNext()){
		//	Node iteratorNode=inOrderIterator.Next();
		//	Console.Write(iteratorNode.value+"-");
		//}
		PreOrderTravel(root);
		Console.WriteLine();
		PreOrderRecursive(root);
	}

}