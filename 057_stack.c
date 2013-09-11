#include <stdio.h>
#include <limits.h>

typedef struct node{
	int* value;
	struct node* next
}Node, *NotePtr;

void Push(Node** head, int value){
		Node* newNode=malloc(sizeof(Node));
		newNode->value=value;
		newNode->next=0;
		if(head==0){
			*head=newNode;
		}else {
			newNode->next=*head;
			*head=newNode;
		} 
};

int Pop(Node** head){
	if(*head==0){
		return INT_MIN;
	}else{
		Node* returnNode=*head;
		*head=(*head)->next;
		int returnValue=returnNode->value;
		free(returnNode) ;
		return returnValue;
	}
};

int Top(Node* head){
	if(head==0){
		return INT_MIN;
	}else{
		return head->value;
	}
};

void Delete(Node** head){
	
}

int main(int argc, char *argv[]) {
	Node* stack=0;
	int a[]={0,1,2,3,4,5,6,7,8,9};
	for (int i=0; i<10; i++) {
		Push(&stack, i);
	}
	printf("top %d", Top(stack));
	return 0;
};