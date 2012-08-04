//http://stackoverflow.com/questions/4542600/interview-question-remove-duplicates-from-an-unsorted-linked-list
//Write code to remove duplicates from an unsorted linked list. FOLLOW UP: How would you solve this problem if a temporary buffer is not allowed?

#include "stdio.h"
#include "stdlib.h"

typedef struct node{
	int value;
	struct node* next;
} Node;


void PrintList(Node* head){
	Node* temp=head;
	while(temp!=0){
		printf("%d\t", temp->value);
		temp=temp->next;
	}
	printf("\n");
}

void DeleteDuplicateFromList(Node* head){
	if(head==0)
		return;	
	Node* temp=head;
	while(temp!=0){
		Node* current=temp;
		while(current!=0 && current->next!=0){
			if(temp->value==current->next->value){
				current->next=current->next->next;
			}
			else {
				current=current->next;	
			}				
		}
		temp=temp->next;
	}			
}

Node* CreateListFromArray(int* a, int length){
	Node* head=0;
	for (int i=0; i<length; i++) {
		Node* node=malloc(sizeof(Node));
		node->value=a[i];
		if(head==0){
			head=node;
			head->next=0;
		}
		else {
			node->next=head;
			head=node;
		}
	}
	return head;	
}

int main(int argc, char const *argv[])
{
	int a[]={2,2,2,2,2,2,1,1,1};
	int length=sizeof(a)/sizeof(*a);
	Node* head=CreateListFromArray(a, length);
	PrintList(head);
	DeleteDuplicateFromList(head);
	PrintList(head);
	return 0;
}