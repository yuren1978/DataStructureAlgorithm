#include <stdio.h>
#include <stdbool.h>
#include <limits.h>

typedef struct treeNode{
	int data;
	struct treeNode* left;
	struct treeNode* right;
} TreeNode;

bool IsBinarySearchTree(TreeNode* root, int minValue, int maxValue){
	if(root!=NULL){
		if(root->value>minValue && root->value<maxValue){
			return IsBinarySearchTree(root->leftChild,minValue,root->value) 
				&& IsBinarySearchTree(root->rightChild, root->value, maxValue) ;
		}else {
			return false;
		}	
	}
	return true;
}

void InOrderPrint(TreeNode* root){
	if(root!=NULL){
		InOrderPrint(root->leftChild);
		printf("%d\t", root->value);
		InOrderPrint(root->rightChild);	
	}
}


TreeNode* CreateTreeFromArray(int* array, int start, int end){
	if(start>end){
		return NULL;
	}
	int middle=(start+end)/2;
	TreeNode* node=malloc(sizeof(TreeNode));
	node->value=array[middle];
	node->leftChild=CreateTreeFromArray(array, start, middle-1);
	node->rightChild=CreateTreeFromArray(array, middle+1, end);
	return node;
}

int main(int argc, char* argv[]){
	int a[]={1,2,3,4,5,6};
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