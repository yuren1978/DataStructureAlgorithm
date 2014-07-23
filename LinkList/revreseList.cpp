#include <iostream>

using namespace std;

struct Node{
	int value;
	Node* next;
	Node(int v):value(v),next(NULL){};
};

Node* createList(){
	Node* head=new Node(1);
	head->next=new Node(2);
	head->next->next=new Node(3);
	return head;
}

Node* reverseRcursively(Node* head){
	if(NULL==head||NULL==head->next)
		return head;

	Node* next=head->next;

	
	Node* reverseHead=reverseRcursively(next);
	
	next->next=head;
	head->next=NULL;

	return reverseHead;
}

Node* reverse(Node* head){
	if(NULL==head || NULL==head->next)
		return head;

	Node* prev=NULL;
	Node* current=head;

	while(current){
		Node* next=current->next;
		current->next=prev;
		prev=current;
		current=next;
	}
	return prev;
}

void printList(Node* head){
	Node* current=head;
	while(current){
		cout<<current->value;
		current=current->next;
	}
	cout<<endl;
}

int main(int argc, char const *argv[])
{
	Node* head=createList();
	printList(head);
	Node* reverseHead=reverseRcursively(head);
	printList(reverseHead);	
	return 0;
}

