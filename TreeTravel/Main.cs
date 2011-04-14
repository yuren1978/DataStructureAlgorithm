using System;
using System.Text;

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
			int sizeOfTree=Size(root);
			Console.WriteLine("size of the tree is "+sizeOfTree); 
			Console.ReadLine();
			int detpthOfTree=MaxDepth(root);
			Console.WriteLine("----Max Depth of the Tree-------"+detpthOfTree);
            Console.ReadLine();
			Console.WriteLine("----Pre Order-------");
			PreOrder(root);
			Console.ReadLine();
			Console.WriteLine("----In Order-------");
			InOrder(root);
			Console.ReadLine();
			Console.WriteLine("----Post Order-------");
			PostOrder(root);
			Console.ReadLine();
			SerializeTreePreOrder(root);
			StringBuilder serializeTreestring=new StringBuilder();
			SerializeTreePreOrder(root, ref serializeTreestring);
			Console.WriteLine("---serialized string is ----"+serializeTreestring.ToString());
			
			
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
		
		public static void PreOrder(BinaryTreeNode root){
			if(root!=null)
			{
				Console.WriteLine(root.value);
				PreOrder(root.leftChild);
				PreOrder(root.rightChild);
			}
		}
		
		
			public static void InOrder(BinaryTreeNode root){
			if(root!=null)
			{
				
				InOrder(root.leftChild);
				Console.WriteLine(root.value);
				InOrder(root.rightChild);
			}
		}
			
			public static void PostOrder(BinaryTreeNode root){
				if(root!=null)
				{
					PostOrder(root.leftChild);
					PostOrder(root.rightChild);
					Console.WriteLine(root.value);
				}
			}
		
		
		
		public static int Size(BinaryTreeNode root)
		{
			if(root!=null)
				return 1+Size(root.leftChild)+Size(root.rightChild);
			else
				return 0;
		}
		
		public static int MaxDepth(BinaryTreeNode root)
		{
			if(root !=null)
			{
				return 1+Math.Max( MaxDepth(root.leftChild), MaxDepth(root.rightChild));
			}
			else{
				return -1;
			}
		}
		
		public static void SerializeTreePreOrder(BinaryTreeNode root)
		{ 
			if(root==null)
			{
				Console.WriteLine("#");
			}
			else
			{
				Console.WriteLine(root.value);
				SerializeTreePreOrder(root.leftChild);
				SerializeTreePreOrder(root.rightChild);
			}
		}
		
		public static void SerializeTreePreOrder(BinaryTreeNode root, ref StringBuilder treeString)
		{
			if(root==null)
			{
				treeString.Append("#");
			}
			else {
				treeString.Append(root.value);
				SerializeTreePreOrder(root.leftChild, ref treeString);
				SerializeTreePreOrder(root.rightChild, ref treeString);
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

