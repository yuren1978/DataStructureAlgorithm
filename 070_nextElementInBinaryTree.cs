using System;
using System.Diagnostics;
using System.Collections.Generic;



public class Node{
	public int value {get;set;}
	public Node left {get;set;}
	public Node right {get;set;}
}

public class NextElementInBinaryTree{

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

	static Node GetNextElement(Node root, int value){
			bool currentFound=false;
			
			Stack<Node> stack=new Stack<Node>();
			Node current=root;
			while (stack.Count>0 || current!=null  ) {
				while(current!=null){
					stack.Push(current);
					current=current.left;
				}
				
				current=stack.Pop();
							if(currentFound){
						return current;
					}		
					if(current.value==value)
						currentFound=true;
					Console.Write(current.value+" ");
					current=current.right;
				
			}
			return null;
	}
	
	
	static Node GetNextElement2(Node root, int value){

					
					Stack<Node> stack=new Stack<Node>();
					Node prev=null;
					Node current=root;
					while (stack.Count>0 || current!=null  ) {
						while(current!=null){
							stack.Push(current);
							current=current.left;
						}
						
							current=stack.Pop();
							if(prev!=null && prev.value==value){
								return current;
							}
							prev=current;
							current=current.right;
						}
					
					return null;

	}
	

	static void Main(){
		int[] a={1,2,3,4,5,6,7,8,9,10};

		Node root=CreateTreeFromArray(a, 0, a.Length-1);
		Debug.Assert(5==GetNextElement2(root, 4).value) ;
		Debug.Assert(2==GetNextElement2(root, 1).value) ;
		Debug.Assert(3==GetNextElement2(root, 2).value) ;
		Debug.Assert(10==GetNextElement2(root, 9).value) ;
		Debug.Assert(null==GetNextElement2(root, 10)) ;
	}

}