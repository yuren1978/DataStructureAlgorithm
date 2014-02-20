#include <stdio.h>
#include <stdlib.h>

typedef struct node{
	int value;
	struct node* next;
} Node;

Node* CreateListFromArray(int* array, int length){
	Node* head=0;
	for (int index=0; index<length; index++) {
		Node* newNode=malloc(sizeof(Node));
		newNode->value=array[index];
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

Node* FindLastNNode(Node* head, int n){
	Node* lastNNode=head;
	Node* nextNode=head;
	for (int index=0; index<n; index++) {
		nextNode=nextNode->next;
		if(nextNode==0){
			lastNNode=0;
			break;
		}
	}
	if(lastNNode!=0){
		while (nextNode!=0) {
			nextNode=nextNode->next;
			lastNNode=lastNNode->next;
		}
	}
	return lastNNode;	
}

int main(int argc, char *argv[]) {
	int a[]={1,2,3,4,5,6,7,8,9,10};
	//created array 10,9,8,7,6,5,4,3,2,1
	int length=sizeof(a)/sizeof(*a);
	Node* head=CreateListFromArray(a, length);
	Node* lastNNode=FindLastNNode(head, 0);
	printf("%d\n", lastNNode->value);
}