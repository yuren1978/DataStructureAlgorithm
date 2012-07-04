#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

typedef enum  {false, true} bool;

typedef struct treeNode{
	int value;
	struct treeNode* left;
	struct treeNode* right;
} TreeNode;


void InOrderPrint(TreeNode* root){
	if(root!=NULL){
		InOrderPrint(root->left);
		printf("%d\t", root->value);
		InOrderPrint(root->right);	
	}
}



TreeNode* CreateTreeFromArray(int* array, int start, int end){
	if(start>end){
		return NULL;
	}
	int middle=(start+end)/2;
	TreeNode* node=malloc(sizeof(TreeNode));
	node->value=array[middle];
	node->left=CreateTreeFromArray(array, start, middle-1);
	node->right=CreateTreeFromArray(array, middle+1, end);
	return node;
}

bool IsBinarySearchTree(TreeNode* root, int min, int max){
	if(root!=NULL){
		if(root->value>min && root->value <max){
			return IsBinarySearchTree(root->left, min, root->value)
				&& IsBinarySearchTree(root->right, root->value, max);
		}
		else {
			return false;
		}		
	}
	else {
		return true;
	}
}

int main(int argc, char* argv[]){
	int a[]={1,2,3,4,5,6,7};
	int sizeOfArray=sizeof(a)/sizeof(*a);
	TreeNode* root=CreateTreeFromArray(a,0,sizeOfArray-1 );
	InOrderPrint(root);
	bool isBinaryTree= IsBinarySearchTree(root, INT_MIN, INT_MAX);
	if(isBinaryTree){
		printf("\nBinary Tree");
	}
	else {
		printf("\nNot Binary Tree");
	}
}