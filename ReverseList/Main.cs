using System;

namespace ReverseList
{
	
	class Node
	{
		public int value;
		public Node next;
	}
	
	class List
	{
		public Node head;
	}
	
	class MainClass
	{
		public static void Main (string[] args)
		{
			List list=new List();
			int[] a={1,2,3,4,5};
			list.head=ArrayToList(a);
			PrintList(list);
			ReverseList(list);
			Console.WriteLine("----- After Revese List ----");
			PrintList(list);
			Console.ReadLine();
		}
		
		public static Node ArrayToList(int[] data)
		{
			Node head=null;
			for(int index=0; index<data.Length; index++)
			{
				Node node=new Node(){value=data[index]};
				if(head==null)
					head=node;
				else
				{
					node.next=head;
					head=node;
				}
			}
			return head;
		}
		
		public static void PrintList(List list)
		{
			Node current=list.head;
			while(current!=null)
			{
				Console.Write(current.value);
				Console.Write(" #");
				current=current.next;
			}
			Console.WriteLine();
		}
		
		
		public static void ReverseList(List list)
		{
			Node prev=null;
			Node current=list.head;
			while(current!=null)
			{
				Node next=current.next;
				current.next=prev;
				prev=current;
				current=next;
			}
			list.head=prev;
		}
	}
}

