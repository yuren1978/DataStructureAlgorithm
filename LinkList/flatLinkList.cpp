// Given a doubly linked list, besides the next and previous pointers, each 
// element has a child pointer, which may or may not point to a separate doubly
// linked list. These child lists may have one or more children of their own. 
// Now do the following:

// a.    Flattern this multilevel data structure
// b.    Restore the original structure from the flatterned structure

// e.g.

// L1 --> L2 --> L3 --> L7 --> L8
//                      |
//                      v
//                     L4 --> L5-->L6


// WIll be flattened to
// L1 --> L2 --> L3 -->L4 -->L5-->L6-->L7-->L8


#include <iostream>
#include <cstdio>
#include <cstdlib>

using namespace std;

struct Node{
	int val;
	Node* next;
	Node* child;
	Node(int value):val(value),next(NULL),child(NULL) {}
};


Node* createTree(){
	Node* head=new Node(1);
	head->next=new Node(2);
	head->next->next=new Node(3);
	head->next->next->next=new Node(7);
	head->next->next->next->next=new Node(8);

	head->next->next->child=new Node(4);
	head->next->next->child->next=new Node(5);
	head->next->next->child->next->next=new Node(6);

	head->next->next->child->next->child=new Node(50);
	head->next->next->child->next->child->next=new Node(51);

	return head;
}


void printList(Node* head){
	cout<<"Print List ";
	Node* temp=head;
	while(temp){
		cout<<temp->val<<" ";
		temp=temp->next;
	}
	cout<<endl;
}

//to be implemented
Node* flatList(Node* head, Node*& tail){
	if(NULL==head){
		tail=NULL;
		return NULL;
	}
	
	Node* temp=head;
	while(temp){

		Node* next=temp->next;

		if(temp->child){
			cout<<"temp value "<<temp->val<<" child value "<<temp->child->val <<endl;
			
			Node* flatTail=NULL;
			Node* flatHead=flatList(temp->child, flatTail);

			temp->child=NULL;
			temp->next=flatHead;
			flatTail->next=next;
		}

		if(temp->next==NULL)
			tail=temp;
		temp=temp->next;
	}

	return head; 
}



int main(int argc, char const *argv[])
{
	Node* head=createTree();
	printList(head);
	Node* temp=NULL;
	Node* flatHead=flatList(head, temp);
	printList(flatHead);
	return 0;
}
