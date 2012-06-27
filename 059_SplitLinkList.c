#include <stdio.h>

typedef struct node{
	int value;
	struct node* next;
} Node;

Node* CreateListFromArray(int* a , int length)
{
	Node* head=0;
	for (int index=0; index<length;index++) {
		Node* newNode=malloc(sizeof(Node));
		newNode->value=a[index];
		if(head==0){
			newNode->next=0;
			head=newNode;
		}
		else {
			newNode->next=head;
			head=newNode;
		}		
	}
	return head;
}

void PrintList(Node* head){
	Node* traversePointer=head;
	while(traversePointer!=0){
		printf("%d -\t", traversePointer->value);
		traversePointer=traversePointer->next;
	}
}

Node* SplitList(Node* head)
{//return the head of the second half.
	Node* fast=head;
	Node* slow=head;
	Node* beforeSlow=0;
	while(fast!=0 && slow!=0 && fast->next!=0){
		fast=fast->next;
		fast=fast->next;
		beforeSlow=slow;
		slow=slow->next;
	}
	Node* returnHead=slow;
	if(beforeSlow!=0){
		beforeSlow->next=0;
	}
	return returnHead;
}

int main(int argc, char *argv[]) {
	int a[]={11,7,5,3,2,1};
	int length=sizeof(a)/sizeof(*a);
	Node* head=CreateListFromArray(a,length);
	PrintList(head);
	Node* splitListHead=SplitList(head);
	printf("\n First Half \t");
	PrintList(head);
	printf("\n Second Half \t");	
	PrintList(splitListHead);
}