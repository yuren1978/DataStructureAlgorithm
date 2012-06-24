//TODO:http://www.mitbbs.com/article_t/JobHunting/32113255.html
using System;
using System.Collections.Generic;

public class Node
{
	public int value;
	public Node left;
	public Node right;	
}



class TreeByLevel
{
	static Node CreateTree(int[] array, int start, int end)
	{
		if(start<=end){
			int middle=(start+end)/2;
			Node node=new Node();
			node.value=array[middle];
			node.left=CreateTree(array, start, middle-1);
			node.right=CreateTree(array, middle+1, end);
			return node;
		}
		else {
			return null;
		}
	}

	static void Main()
	{
		int[] a={1,2,3,4,5,6,7,8,9};
		Node root=CreateTree(a,0, a.Length-1);
		Console.WriteLine("Print Tree By Level");
		BFSPrintTreeByLevel(root);
		
	}
}