using System;

namespace TreeTravel
{
	class MainClass
	{
		private static int index=0;
		public static void Main (string[] args)
		{
			//Console.WriteLine ("Hello World!");
			int?[] a={1 ,2,null,3, null, null,4, 5, null, null, 6, null, null }; 
			BinaryTreeNode root=CreateBinaryTree(a);
            Console.ReadLine();
		}
		
		public static BinaryTreeNode CreateBinaryTree(int?[] array)
		{//use recursive function.
            Console.WriteLine(index);
			if(array[index]!=null)
			{                
				BinaryTreeNode node=new BinaryTreeNode();
				node.value=array[index].Value;
				index++;
				node.leftChild=CreateBinaryTree(array);
				index++;
				node.rightChild=CreateBinaryTree(array);
				return node;
			}
			else {
				return null;
			}
		}
	}
	
	public class BinaryTreeNode
	{
		
		public int value;
		public BinaryTreeNode leftChild;
		public BinaryTreeNode	rightChild;
		
	}
}

