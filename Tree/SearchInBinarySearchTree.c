#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

typedef struct node {
	int value;
	struct node* left;
	struct node* right;
} TreeNode;

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

TreeNode* FindNodeInTree(const TreeNode* root , int value){
	TreeNode* currentNode=root;
	while (currentNode!=NULL) {
		if(currentNode->value<value){
			currentNode=currentNode->right;
		}
		else if (currentNode->value>value) {
			currentNode=currentNode->left;
		}
		else {
			return currentNode;
		}
	}
	return NULL;
}

int main(int argc, char *argv[]) {
	int a[]={1,2,3,4,5,6,7,8,9,10};
	int length=sizeof(a)/sizeof(*a);
	TreeNode* root=CreateTreeFromArray(a, 0, length-1);
	assert(1==FindNodeInTree(root,1)->value);
	assert(10==FindNodeInTree(root,10)->value);
	assert(5==FindNodeInTree(root,5)->value);
	assert(NULL==FindNodeInTree(root,11));
}