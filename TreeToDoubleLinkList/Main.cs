using System;

namespace TreeToDoubleLinkList
{
	
	public class Node
	{
		public int value;
		public Node leftChild;
		public Node rightChild;
	}
	
	class MainClass
	{
		public static void Main (string[] args)
		{
			//Create a tree
			Node root=CreateTree();
			InOrderTravel(root);
			Node head= ConvertToDoubleList(root);
		}
		
		
		private static Node CreateTree()
		{
			Node root=new Node(){value=4, leftChild=null, rightChild= null};
			root.leftChild=new Node(){value=2, leftChild=null, rightChild= null};
			root.rightChild=new Node{value=5, leftChild=null, rightChild= null};
			root.leftChild.leftChild=new Node(){value=1, leftChild=null, rightChild= null};
			root.leftChild.rightChild=new Node(){value=3, leftChild=null, rightChild= null};
			return root;
		}
		
		private static void InOrderTravel(Node root)
		{
			if(root !=null)
			{
				InOrderTravel(root.leftChild);
				Console.WriteLine(root.value);
				InOrderTravel(root.rightChild);
			}
		}
	}
}

