using System;
using System.Collections.Generic;

namespace TreeTravelNonRecursive
{
	public class Node
	{
		public Node left;
		public Node right;
		public int id;
	}
	
	class MainClass
	{
		//private static int _counter=0;
		public static void Main (string[] args)
		{
			//Create a tree
			Node root=CreateTree();
			//Pre-Order Travel the tree
			Console.WriteLine("---Start Print Tree Pre Order Recursive----");
			PreOrderTravelRecursive(root);
			
			Console.WriteLine("---Start Print Tree Pre Order NonRecursive----");
			PreOrderTravelNonRecursive(root);
			
			Console.WriteLine("---Start Print Tree In Order Recursive----");
			InOrderTravelRecursive(root);
			
			Console.WriteLine("---Start Print Tree In Order NonRecursive----");
			InOrderTravelNonRecursive(root);
			
			//Travel the tree
			Console.ReadLine();
		}
		
		
		private static Node CreateTree()
		{
			Node root=new Node(){id=1};
			root.left=new Node(){id=2};
			root.right=new Node(){id=3};
			root.left.left=new Node{id=4};
			root.left.right=new Node{id=5};
			root.right.left=new Node{id=6};
			return root;
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
					Console.WriteLine(topOfstack.id);
					if(topOfstack.right !=null)
						stackNodes.Push(topOfstack.right);
					if(topOfstack.left!=null)
						stackNodes.Push(topOfstack.left);
				}
			}
		}
		
		
		private static void InOrderTravelNonRecursive(Node root)
		{
			Stack<Node> stackNodes=new Stack<Node>();
			Node currentNode=root;
			bool done=false;
			while(!done)
			{
				if(currentNode!=null)
				{//push the node, it could be either left node or right node
					stackNodes.Push(currentNode);
					currentNode=currentNode.left;
				}
				else {//current node is null
					if(stackNodes.Count==0)
						done=true;
					else {
						currentNode= stackNodes.Pop();
						Console.WriteLine(currentNode.id);
						currentNode=currentNode.right;
					}
					
				}
			}
		}
		
		
		
		private static void PreOrderTravelRecursive(Node root)
		{
			if(root!=null)
			{
				Console.WriteLine(root.id);
				PreOrderTravelRecursive(root.left);
				PreOrderTravelRecursive(root.right);
			}
		}
		
		
		private static void InOrderTravelRecursive(Node root)
		{
			if(root !=null)
			{
				InOrderTravelRecursive(root.left);
				Console.WriteLine(root.id);
				InOrderTravelRecursive(root.right);
			}
		}
	}
}

