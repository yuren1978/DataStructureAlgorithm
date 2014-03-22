#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

typedef enum  {false, true} bool;

typedef struct treeNode{
	int value;
	struct treeNode* left;
	struct treeNode* right;
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

bool TreeSame(TreeNode* root1, TreeNode* root2){
	
}

int main(int argc, char *argv[]) {
	int a[]={1,2,3,4,5,6,7};
	int b[]={1,2,3,4,5,6};
	TreeNode* tree1=CreateTreeFromArray(a,0,6);
	TreeNode* tree2=CreateTreeFromArray(a,0,6);
	assert(true==TreeSame(tree1, tree2));
}