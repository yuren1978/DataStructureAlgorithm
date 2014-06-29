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
	
	class InOrderIterator
	{
		private Stack<Node> stack=new Stack<Node>();
		
		
		public InOrderIterator(Node root){
			while(root!=null){
				stack.Push(root);
				root=root.left;			
			}
		}
		
		public bool HasNext {
			get {return stack.Count>0 ;}	
		}
		
		public Node GetNext(){
			Node current=stack.Pop();
			Node right=current.right;
			while (right!=null) {
				stack.Push(right);
				right=right.left;
			}
			return current;
		}
	}
	
	class PreOrderIterator
	{
		private Stack<Node> stack=new Stack<Node>();				
		public PreOrderIterator(Node root){
			if(root!=null){
				stack.Push(root);
			}	
		} 
		
		public bool HasNext {
			get {return stack.Count>0 ;}
		}
		
		public Node GetNext(){
			Node node=stack.Pop();
			if(node.right!=null){
				stack.Push(node.right);
			}
			if(node.left!=null){
				stack.Push(node.left);					}							
			return node;			
		}				
	}
	
	static void InOrderNonRecursive(Node root){
		Node current=root;
		Stack<Node> stack=new Stack<Node>();
		while(current!=null||stack.Count>0){
			if(current!=null){
				stack.Push(current);
				current=current.left;
			}
			else {
				current=stack.Pop();
				if(current!=null){
					Console.Write(current.value+" ");
					current=current.right;
				}	
			}
		}
	}

	static void PreOrderNonRecursive(Node root){
		Console.WriteLine("Binary Tree InOrder NonRecursive");
		if(root==null)
			return;
		Stack<Node> stack=new Stack<Node>();
		stack.Push(root);
		while (stack.Count>0) {
			Node current=stack.Pop();
			Console.Write(current.value+" ");
			if(current.right!=null){
				stack.Push(current.right);
			}
			if(current.left!=null){
				stack.Push(current.left);
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

	static void PreOrderTravel(Node root){
		if(root!=NULL){
			Console.Write(root.value);
			Console.Write(" ");
			PreOrderTravel(root.left);
			PreOrderTravel(root.right);
		}
		Console.Write(" ");
	}


	static void Main(){
		int[] a={1,2,3,4,5,6,7,8,9,10};
		Node root=CreateTreeFromArray(a, 0, a.Length-1);
		//InOrderNonRecursive(root);
		//PreOrderNonRecursive(root);
		//PreOrderTravel(root);
		//InOrderIterator inOrderIterator=new InOrderIterator(root);
		//while(inOrderIterator.HasNext){
		//	Node iteratorNode=inOrderIterator.GetNext();
		//	Console.Write(iteratorNode.value+"-");
		//}
		//PreOrderTravel(root);
		//Console.WriteLine();
		//PreOrderRecursive(root);
		//PreOrderNonRecursive(root);
		//InOrderNonRecursive(root);
		//PreOrderIterator preOrderIterator=new PreOrderIterator(root);
		//while (preOrderIterator.HasNext) {
			//Console.WriteLine("value is :"+ preOrderIterator.GetNext().value  );
		//}		
		//InOrderIterator inOrderIterator=new InOrderIterator(root);
		//while (inOrderIterator.HasNext()) {
		//	Console.WriteLine("value is :"+ inOrderIterator.Next.value  );
		//}
	}

}