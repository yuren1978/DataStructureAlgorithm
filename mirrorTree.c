//http://codercareer.blogspot.com/2011/10/no-12-mirror-of-binary-trees.html
//Please implement a function which returns mirror of a binary tree

#include <stdio.h>

typedef struct node{
	int value;
	struct node* left;
	struct node* right;
} Node;

Node* CreateTreeFromArray(int* array , int start,int end){
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

PreOrder(Node* root){
	if(root!=0){
		printf("%d\t", root->value);
		PreOrder(root->left);
		PreOrder(root->right);
	}
}

void MirrorTree(Node* root){
	if(root==0)
		return;
	Node* leftTree=root->left;
	if(root->right!=0){
		root->left=root->right;
		root->right=leftTree;
	}
	MirrorTree(root->left);
	MirrorTree(root->right);				
}

int main(int argc, char *argv[]) {
	int a[]={1,2,3,5,6,7,8};
	int length=sizeof(a)/sizeof(*a);
	Node* root=CreateTreeFromArray(a,0, length-1);
	printf("Before Mirror \n");
	PreOrder(root);
	MirrorTree(root);
	printf("After Mirror \n");
	PreOrder(root);	
}