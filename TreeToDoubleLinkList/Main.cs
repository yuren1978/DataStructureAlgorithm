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
			PrintCircularList(head);
		}
		
		
		private static Node ConvertToDoubleList(Node node)
		{
			if(node==null) return null;
			Node leftList=ConvertToDoubleList(node.leftChild);
			Node rightList=ConvertToDoubleList(node.rightChild);
			
			node.leftChild=node;
			node.rightChild=node;
			
			leftList=Merge(leftList, node);
			leftList=Merge(leftList, rightList);
			return leftList;
		}
		
		private static void PrintCircularList(Node head)
		{
			Node current=head;
			do {
				Console.WriteLine(current.value);
				current=current.rightChild;
			} while (current!=head);
		}
		
		private static Node Merge(Node leftList, Node rightList)
		{
			if(leftList==null) return rightList;
			if(rightList==null) return leftList;
			Node lastNodeInLeftList=leftList.leftChild;
			Node lastNodeInrightList=rightList.leftChild;
			
			lastNodeInLeftList.rightChild=rightList;
			rightList.leftChild=lastNodeInLeftList;
			leftList.leftChild=lastNodeInrightList;
			lastNodeInrightList.rightChild=leftList;
			
			return leftList;
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

