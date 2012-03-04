#include <stdio.h>

typedef struct node {
	int value;
	struct node* next;
} Node;

typedef struct treeNode{
	int value;
	struct treeNode* leftChild;
	struct treeNode* rightChild;
} TreeNode;

Node* CreateNodeFromList(int* a, int length){
	Node* head=0;
	for (int index=0; index<length; index++) {
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
	Node* travelHead=head;
	while (travelHead!=0) {
		printf("%d \t ", travelHead->value);
		travelHead=travelHead->next;
	}
}


Node* SplitList(Node* head)
{
	Node* fast=head;
	Node* slow=head;
	while(fast!=0 && slow!=0 && fast->next!=0)
	{
		fast=fast->next;
		fast=fast->next;
		slow=slow->next;
	}
	Node* middle=slow->next;
	slow->next=0;
	return middle;
}

TreeNode* MakeTree(Node* head)
{
	Node* middle=SplitList(head);
	TreeNode* root=malloc(sizeof(TreeNode));
}

TreeNode* SortedLinkListToBinaryTree(Node* head){
	Node* middle=SplitList(head);
	TreeNode* root=malloc(sizeof(TreeNode));
	root->value=middle->value;
	root->leftChild=MakeTree(head);
	root->rightChild=MakeTree(middle->next);
}

int main(int argc, char *argv[]) {
	int a[]={10,9,8,7,6,5,4,3,2,1};
	int length=sizeof(a)/sizeof(*a);
	Node* head=CreateNodeFromList(a, length);
	TreeNode* rootNode=SortedLinkListToBinaryTree(head);
	PrintList(head);
}