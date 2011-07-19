using System;

namespace PopulateNextRightPointerEachNode
{
	public class Node
	{
		public int value;
		public Node left;
		public Node right;
		public Node next;
	}
	
	class MainClass
	{
		public static void Main (string[] args)
		{
			Node nullNode=null;
			PopulateNextRightPointerEachNode(nullNode);
			
			Node singlNode=new Node(){value=1, left=null, right=null, next=null};
			PopulateNextRightPointerEachNode(singlNode);
		}
		
		private static void PopulateNextRightPointerEachNode(Node root)
		{
			if(root==null)
				return;
		
			if(root.left==null || root.right==null)
				return;
			
		}
	}
}
