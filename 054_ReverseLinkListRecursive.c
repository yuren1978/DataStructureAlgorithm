#include <stdio.h>

typedef struct node{
	int value;
	struct node* next;
} Node;

Node* CreateLinkListFromArray(int* a, int start, int end){
	Node* head=0;
	for (int index=start; index<end; index++) {
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
	Node* travelPointer=head;
	while(travelPointer!=0){
		printf("%d\t", travelPointer->value);
		travelPointer=travelPointer->next;
	}
}

Node* ReverseList(Node* head){
	Node* reverseHead;
	Node* nextNode;
	if(head==0)
		reverseHead=0;		
	nextNode=head->next;
	if(nextNode==0){
		reverseHead=head;	
	}
	else {
		Node* tempNextNode=nextNode;
		reverseHead=ReverseList(nextNode);
		tempNextNode->next=head;
		head->next=0;
	}		
	return reverseHead;	
}


int main(int argc, char *argv[]) {
	int a[]={1,2};
	int length=sizeof(a)/sizeof(*a);
	Node* head=CreateLinkListFromArray(a, 0, length);
	PrintList(head);
	Node* reverseHead= ReverseList(head);
	PrintList(reverseHead);
	return 0;
}