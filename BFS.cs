using System;
using System.Collections.Generic;

class Node
{
	public int value;
	public Node leftChild=null;
	public Node rightChild=null;
}


class BFS
{
	private static void InOrderPrint(Node root)
	{
		if(root!=null)
		{
			InOrderPrint(root.leftChild);
			Console.Write(root.value);
			InOrderPrint(root.rightChild);
		}
	}

	private static Node ConvertArrayToTree(int[] a, int start, int end)
	{
		if(start<=end)
		{
			int middle=(start+end)/2;
			Node node=new Node();
			node.value=a[middle];
			node.leftChild=ConvertArrayToTree(a, start, middle-1);
			node.rightChild=ConvertArrayToTree(a, middle+1, end);
			return node;
		}
		else
		{
			return null;
		}
	}

	private static void BreathFirstSearch(Node root)
	{
		Queue<Node> queue=new Queue<Node>();
		queue.Enqueue(root);
		while(queue.Count>0)
		{
			Node dequeNode=queue.Dequeue();
			Console.Write(dequeNode.value);
			if(dequeNode.leftChild!=null)
				queue.Enqueue(dequeNode.leftChild);
			if(dequeNode.rightChild!=null)
				queue.Enqueue(dequeNode.rightChild);		
		}	
	}

	public static void Main()
	{
		int[] a={1,2,3,4,5,6,7,8,9,10};
		Node root=ConvertArrayToTree(a, 0, a.Length-1);
		InOrderPrint(root);
		Console.WriteLine("Finish Printing");
		BreathFirstSearch(root);
	}
}