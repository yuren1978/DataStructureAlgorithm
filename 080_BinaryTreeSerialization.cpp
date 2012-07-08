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
	TreeNode* node=new TreeNode();
	node->value=array[middle];
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
	while (index<length) {
		int digit=array[index];
		if(digit=='#'){
			return NULL;
		}
		else {
			TreeNode* node=new TreeNode();
			node->value=digit;	
			node->left=ReCreateTreeFromPreOrder(array, ++index, length);
			node->right=ReCreateTreeFromPreOrder(array, ++index, length);
			return node;
		}
	}
}

int main(int argc, char *argv[]) {
	int a[]={1,2,3,4,5,6,7,8,9,10};
	int length=sizeof(a)/sizeof(*a);
	TreeNode* root=CreateTreeFromArray(a, 0, length-1);
	printf("\n Pre Order Print \t");
	PreOrderPrint(root);
	int preOrder[]={5,2,1,'#','#',3,'#',4,'#','#',8,6,'#',7,'#','#',9,'#',10,'#','#'};
	length=sizeof(preOrder)/sizeof(*preOrder);
	int index=0;
	root=ReCreateTreeFromPreOrder(preOrder,index, length);
	printf("\n Pre Order Print \t");
	PreOrderPrint(root);
}