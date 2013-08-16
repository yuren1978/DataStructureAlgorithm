#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

//int in_order[] = {6,2,7,1,5,3,4,8,9,10};
//int pre_order[] = {5,2,6,1,7,4,3,9,8,10};
//TreeNode* tree = create_tree(pre_order, in_order, 10);

typedef struct node {
	int value;
	struct node* left;
	struct node* right;
} TreeNode;

void InOrderTravel(TreeNode* root){
	if(root!=NULL){
		InOrderTravel(root->left);
		printf("%d\t", root->value);
		InOrderTravel(root->right);
	}
}

void PreOrderTravel(TreeNode* root){
	if(root!=NULL){
		printf("%d\t", root->value);
		PreOrderTravel(root->left);
		PreOrderTravel(root->right);
	}
}



TreeNode* CreateTreeFromInOrderAndPreOrder(int* in_order, int* pre_order, int length)
{
}



int main(int argc, char *argv[]) {
	int in_order[] = {6,2,7,1,5,3,4,8,9,10};
	int pre_order[] = {5,2,6,1,7,4,3,9,8,10};
	int length=sizeof(in_order)/sizeof(*in_order);
	TreeNode* root=CreateTreeFromInOrderAndPreOrder(in_order, pre_order, length);
	assert(root->value==5);
	printf("\n In Order :");
	InOrderTravel(root);
	printf("\n Pre Order :");
	PreOrderTravel(root);
}