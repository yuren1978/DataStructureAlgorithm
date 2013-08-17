#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

struct TreeNode {
	int value;
	TreeNode* left;
	TreeNode* right;
	TreeNode(int x):value(x), left(NULL), right(NULL) {}
} ;

TreeNode* CreateTreeFromArray(int* array, int start, int end){
	if(start>end){
		return NULL;
	}
	int middle=(start+end)/2;
	TreeNode* node=new TreeNode(array[middle]);
	node->left=CreateTreeFromArray(array, start, middle-1);
	node->right=CreateTreeFromArray(array, middle+1, end);
	return node;
}

void PreOrderPrint(TreeNode* root){
	if(root==NULL){
		printf("#\t");
	}
	else {
		printf("%d\t", root->value);
		PreOrderPrint(root->left);		
		PreOrderPrint(root->right);
	}
}

TreeNode* ReCreateTreeFromPreOrder(int* array, int& index, int length){
	if(index>=length|| '#'==array[index]){
		return NULL;
	}
	TreeNode* node=new TreeNode(array[index]);
	index++;
	node->left=ReCreateTreeFromPreOrder(array, index , length);
	index++;
	node->right=ReCreateTreeFromPreOrder(array, index, length);
	return node;
}

int main(int argc, char *argv[]) {
	int a[]={1,2,3};
	int length=sizeof(a)/sizeof(*a);
	TreeNode* root=CreateTreeFromArray(a, 0, length-1);
	printf("\n Pre Order Print \t");
	PreOrderPrint(root);
	int preOrder[]={2,1,'#','#',3,'#','#'};
	length=sizeof(preOrder)/sizeof(*preOrder);
	int index=0;
	root=ReCreateTreeFromPreOrder(preOrder,index, length);
	printf("\n Pre Order Print \t");
	PreOrderPrint(root);
}