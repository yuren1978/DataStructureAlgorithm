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
			Console.WriteLine("---Start Print Tree Pre Order----");
			PreOrderTravel(root);
			
			Console.WriteLine("---Start Print Tree Pre Order NonRecursive----");
			PreOrderTravelNonRecursive(root);
			
			Console.WriteLine("---Start Print Tree In Order----");
			InOrderTravel(root);
			
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
		
		
		
		
		private static void PreOrderTravel(Node root)
		{
			if(root!=null)
			{
				Console.WriteLine(root.id);
				PreOrderTravel(root.left);
				PreOrderTravel(root.right);
			}
		}
		
		
		private static void InOrderTravel(Node root)
		{
			if(root !=null)
			{
				InOrderTravel(root.left);
				Console.WriteLine(root.id);
				InOrderTravel(root.right);
			}
		}
	}
}

