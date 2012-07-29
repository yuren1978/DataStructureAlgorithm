//Three task
//1. pre order non recursive
//2. in order non recursive
//3. create an iterator for pre order
//4. create an iterator for in order
using System;
using System.Collections.Generic;


public class BinaryTreeInOrderNonRecursive{

	class Node{
		public int value {get;set;}
		public Node left {get;set;}
		public Node right {get;set;}
	}
	
	class InOrderIterator{
		private Stack<Node> _stack=new Stack<Node>();
		
		public InOrderIterator(Node root){
			while (root!=null) {
				_stack.Push(root);
				root=root.left;
			}
		}
		
		public bool HasNext(){
			return _stack.Count>0;
		}

		public Node Next{
			get{
				 Node node = _stack.Pop();
				 Node current = node.right;
				 while (current!=null) {
				        _stack.Push(current);
				        current = current.left;
				 }
				 return node;
			}
		}
	}
	
	class PreOrderIterator2{
		
		private Stack<Node> _stack=new Stack<Node>();
		
		public PreOrderIterator2(Node root){
			_stack.Push(root);
		}
		
		public bool HasNext(){
			return _stack.Count>0;
		}
		
		public Node Next{
			get
			{
				Node node=_stack.Pop();
				if(node.right!=null)
					_stack.Push(node.right);
				if(node.left!=null)
					_stack.Push(node.left);
				return node;		
			}
		}
	}
	
	
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

	static void PreOrderRecursive(Node root){
		if(root!=null){
			Console.WriteLine(root.value+"#");
			PreOrderRecursive(root.left);
			PreOrderRecursive(root.right);
		}
	}
	
	static void InOrderNonRecursive(Node root){
		Stack<Node> stack=new Stack<Node>();
		Node current=root;
		while (current!=null || stack.Count>0) {
			if(current!=null){
				stack.Push(current);
				current=current.left;
			}
			else {
				current=stack.Pop();
				if(current!=null){
					Console.WriteLine(current.value);
					current=current.right;
				}
			}
		}
	}
	
	static void PreOrderNonRecursive(Node root){
		Stack<Node> stack=new Stack<Node>();
		Node current=root;
		while (current!=null || stack.Count>0) {
			if(current!=null){
				Console.WriteLine(current.value);
				if(current.right!=null)
					stack.Push(current.right);
				current=current.left;
			}
			else {
				current=stack.Pop();
			}
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
		//PreOrderTravel(root);
		//Console.WriteLine();
		//PreOrderRecursive(root);
		//PreOrderNonRecursive(root);
		//InOrderNonRecursive(root);
		PreOrderIterator2 preOrderIterator=new PreOrderIterator2(root);
		while (preOrderIterator.HasNext()) {
			Console.WriteLine("value is :"+ preOrderIterator.Next.value  );
		}
		
		//InOrderIterator inOrderIterator=new InOrderIterator(root);
		//while (inOrderIterator.HasNext()) {
		//	Console.WriteLine("value is :"+ inOrderIterator.Next.value  );
		//}
	}

}