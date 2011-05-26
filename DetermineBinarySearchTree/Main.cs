using System;

namespace DetermineBinarySearchTree
{
	public class Node
	{
		public int vlaue;
		public Node left;
		public Node right;
	}
		
	
	class MainClass
	{
		
		public static void Main (string[] args)
		{
			Console.WriteLine ("Hello World!");
		}
		
		private static bool IsTreeBinarySearchTree(Node root)
		{
			return IsTreeBinarySearchTreeHelper(root, int.MinValue, int.MaxValue);
		}
		
		private static bool IsTreeBinarySearchTreeHelper(Node node, int minValue, int maxValue)
		{
			if(node==null) //empty node, return null
				return true;
			if(IsTreeBinarySearchTreeHelper(node.left, minValue, node.vlaue)
			   && IsTreeBinarySearchTreeHelper(node.right, node.vlaue, maxValue))
				return true;
			else
				return false;
			
		}
	}
}

