#include <cstdio>
#include <cstdlib>
//http://www.leetcode.com/2011/08/insert-into-a-cyclic-sorted-list.html
//http://www.youtube.com/watch?v=8y5tYB004ss
//Given a node from a cyclic linked list which has been sorted, write a function to insert a value into the list such that it remains a cyclic sorted list. The given node can be any single node in the list.
//A cyclic sorted linked list. Note that the tail is pointing back to its head. The only reference to the list is a given node which can be any node in the list. Let’s say that you need to insert 4 into the list.

typedef struct node{
	int value;
	struct node* next;
} Node;



void PrintList(Node* startNode){
	Node* p=startNode;
	do {
		printf("%d \t", p->value);
		p=p->next;
	} while (p!=startNode) ;
	printf("\n");
}

int main(int argc, char *argv[]) {
	Node* node1=new Node();
	node1->value=1;
	
	Node* node2=new Node();
	node2->value=2;
	
	Node* node3=new Node();
	node3->value=3;
	
	node1->next=node2;
	node2->next=node3;
	node3->next=node1;
	
	PrintList(node1);
	PrintList(node2);
	PrintList(node3);
	
}