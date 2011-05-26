using System;
using System.Collections;
using System.Collections.Generic;

namespace PreOrderNonRecursive
{
	
	public class Node
	{
		public int value;
		public Node left;
		public Node right;
	}
	
	class MainClass
	{
		public static void Main (string[] args)
		{
			Node root=BuildTree();
			PreOrderNonRecur(root);
			Console.WriteLine();
			PreOrderRecur(root);
			Console.WriteLine();
			PreOrderTravelNonRecursive(root);
			Console.ReadLine();
		}
		
		private static void PreOrderRecur(Node node)
		{
			if(node !=null)
			{
				Console.Write(node.value);
				Console.Write(" ");
				PreOrderRecur(node.left);
				PreOrderRecur(node.right);
			}
		}
		
		private static void PreOrderTravelNonRecursive(Node root)
		{
			Stack<Node> stackNodes=new Stack<Node>();
			if(root !=null)
			{
				stackNodes.Push(root);
				while(stackNodes.Count!=0)
				{
					Node topOfstack=stackNodes.Pop();
					Console.Write(topOfstack.value);
					Console.Write(" ");
					if(topOfstack.right !=null)
						stackNodes.Push(topOfstack.right);
					if(topOfstack.left!=null)
						stackNodes.Push(topOfstack.left);
				}
			}
		}
		
		
		
		private static void PreOrderNonRecur(Node root)
		{
			if(root !=null)
			{
				Stack<Node> stack=new Stack<Node>();
				stack.Push(root);
				while(stack.Count>0)
				{
					Node node= stack.Pop();
					if(node!=null)
					{
						Console.Write(node.value);
						Console.Write(" ");
						stack.Push(node.right);
						stack.Push(node.left);
					}
				}
			}
		}
		
		private static Node BuildTree()
		{
			Node node=new Node(){value=1, left=null, right=null};
		
			node.left=new Node(){value=2, left=null, right=null};
			node.right=new Node(){value=3, left=null, right=null};
		
			node.left.left=new Node{value=4, left=null, right=null};
			node.left.right=new Node{value=5, left=null, right=null};
			return node;
		}
	}
}

