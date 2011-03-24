using System;
using System.Collections.Generic;

namespace PrintTreeByLevel
{
	//define a tree node.
	class Node
	{
		
		public int value;
		public Node leftChild;
		public Node rightChild;
	}
	
	
	class MainClass
	{
		public static void Main (string[] args)
		{
			Console.WriteLine ("Start Program");
			int[] a={1,2,3,4,5,6,7,8};
			Node root=CreateTree(a, 0, 8);
			PrintTreeByLeve(root);
            //Try a different tree.

			Console.WriteLine ("End Program");
		}
		
		private static Node CreateTree(int[] array, int i, int length)
		{//use the recursive algorithm to build the tree
			if(i>=length)
				return null;
			Node node=new Node();
			node.value=array[i];
			node.leftChild=CreateTree(array, 2*i+1, length);
			node.rightChild=CreateTree(array, 2*i+2, length);
			return node;
			
		}
		
		private static void PrintTreeByLeve(Node root)
		{
			Queue<Node> queue=new Queue<Node>();
			queue.Enqueue(root);
			while ( queue.Count!=0) {
				Node currentNode=queue.Dequeue();
				Console.WriteLine(currentNode.value);
				if(currentNode.leftChild!=null)
					queue.Enqueue(currentNode.leftChild);
				if(currentNode.rightChild!=null)
					queue.Enqueue(currentNode.rightChild);
			}
		}
	}
}




