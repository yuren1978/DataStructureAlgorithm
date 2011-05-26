using System;

namespace ReveseLinkListRecursive
{
	public class Node
	{
		public int value;
		public Node next;
		public override string ToString()
		{
			return "value "+ value;
		}
	}
	
	
	
	class MainClass
	{
		public static void Main (string[] args)
		{
			Node head=CreateList();
			Node reverseHead=ReverseList(head);
			PrintList(reverseHead);
		}
		
		
		public static void PrintList(Node head)
		{
			
		}
		
		public static Node CreateList()
		{
			Node head=null;
			for(int index=0; index<3; index++)
			{
				Node node=new Node{value=index, next=null};
				if(head==null)
				{
					head=node;
				}
				else 
				{
					node.next=head;
					head=node;
				}
			}
			return head;
		}
		
		public static Node ReverseList(Node head)
		{
			Node nextHead=head.next;
			if(nextHead==null)
			{
				return head;
			}
			else
			{
				Node reverseHead= ReverseList(nextHead);
				nextHead.next=head;
				head.next=null;
				return reverseHead;
			}
		}
	}
}
