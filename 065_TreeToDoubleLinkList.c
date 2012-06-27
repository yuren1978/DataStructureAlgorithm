#include <stdio.h>
#include <stdlib.h>

typedef struct node{
	int value;
	struct node* left;
	struct node* right;
} Node;

Node* CreateTreeFromArray(int* array, int start, int end){
	if(start<=end){
		int middle=(start+end)/2;
		Node* node=malloc(sizeof(Node));
		node->value=array[middle];
		node->left=CreateTreeFromArray(array, start, middle-1);
		node->right=CreateTreeFromArray(array, middle+1, end);
		return node;
	}
	else {
		return 0;
	}
}

void PrintDoubleLinkList(Node* head){
	if(head==0)
		return;
	Node* current=head;
	printf("%d\t", current->value);
	current=current->right;
	while(current!=head){
		printf("%d\t", current->value);
		current=current->right;
	}
}

Node* TreeToDoubleLinkList(Node* root){
	Node* head=0;
	if(root->left==0 && root->right==0){
		head=root;
		root->right=root;
		root->left=root;
	}
	else {
		
		if(root->left!=0){
			Node* leftHead=TreeToDoubleLinkList(root->left);
			Node* leftTail=leftHead->left;
			root->left=leftTail;
			leftTail->right=root;
			leftHead->left=root;
			head=leftHead;
		}
		
		if(root->right!=0){
							Node* rightHead= TreeToDoubleLinkList(root->right);
							Node* rightTail=rightHead->left;
							root->right=rightHead;
							rightHead->left=root;
							if(head==0)
								head=root;		
							rightTail->right=head;
							head->left=rightTail;
						}
						else {
							root->right=head;
						}	
	}
	return head;
}

void InOrderPrint(Node* root){
	if(root!=0){
		InOrderPrint(root->left);
		printf("%d\t", root->value);
		InOrderPrint(root->right);
	}
}

int main(int argc, char *argv[]) {
	int a[]={1,2,3};
	int length=sizeof(a)/sizeof(*a);
	Node* root=CreateTreeFromArray(a, 0, length-1);
	InOrderPrint(root);
	printf("root value %d\n", root->value);
	Node* head=TreeToDoubleLinkList(root);
	printf("\n print double link list:");
	PrintDoubleLinkList(head);
}