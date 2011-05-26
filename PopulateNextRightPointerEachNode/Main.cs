using System;

namespace PopulateNextRightPointerEachNode
{
	public class Node
	{
		int vlaue;
		Node left;
		Node right;
		Node next;
	}
	
	class MainClass
	{
		public static void Main (string[] args)
		{
			Node node=null;
			PopulateNextRightPointerEachNode(node);
		}
		
		private static void PopulateNextRightPointerEachNode(Node root)
		{
			if(root==null)
				return;
		}
	}
}
