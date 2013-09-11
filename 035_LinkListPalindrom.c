
#include <stdio.h>
#include <stdlib.h>

//http://www.geeksforgeeks.org/archives/1072


typedef enum {false,true} bool;

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

bool isPalindrome(Node** left, Node* right){

}


int main(int argc, char *argv[]) {
	int a[]={1,2,3,4,3,2,1};
	Node* head=CreateListFromArray(a,7);
	bool isPalin=isPalindrome(&head, head);
	if(isPalin){
		printf("\n Palindrome");
	}else {
		printf("\n Non-Palindrome");
	}
	
	
	return 0;	
}