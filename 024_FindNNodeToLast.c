#include <stdio.h>
#include <stdlib.h>

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

Node* FindNodeToLast(Node* head, int n){
	if(head==NULL)
		return NULL;
		
	Node* fastNode=head;
	Node* returnNode=head;
	
	for (int i=0; i<n; i++) {
		fastNode=fastNode->next;
		if(fastNode==NULL){
			break;
		}			
	}
	
		while (fastNode!=NULL) {
			fastNode=fastNode->next;
			returnNode=returnNode->next;
		}
	return returnNode;	
}

void PrintList(Node* head){
	Node* travelPointer=head;
	while(travelPointer!=0){
		printf("%d\t", travelPointer->value);
		travelPointer=travelPointer->next;
	}
}

int main(int argc, char *argv[]) {
	int a[]={4,3,2,1};
	int n=0;
	int length=sizeof(a)/sizeof(*a);
	Node* head=CreateLinkListFromArray(a,0,length);
	PrintList(head);
	Node* nodeToLast=FindNodeToLast(head, n);
	if(nodeToLast!=NULL){
		printf("\n%d", nodeToLast->value);	
	}	
}