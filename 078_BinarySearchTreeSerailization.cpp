//http://www.leetcode.com/2010/09/saving-binary-search-tree-to-file.html?utm_source=feedburner&utm_medium=feed&utm_campaign=Feed%3A+ihas1337code+%28LeetCode%29
#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

//typedef enum  {false, true} bool;

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

void PreOrderPrint(TreeNode* root){
	if(root!=NULL){
		printf("%d\t", root->value);
		PreOrderPrint(root->left);
		PreOrderPrint(root->right);	
	}
}


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

TreeNode* CreateBFSFromPreOrderArray(int* array, int length, int& index, int min, int max ){
	printf("\n length is %d index is %d and  value is %d min is %d and max is %d", length, index, array[index], min, max);
	if  (array[index]>min && array[index]<max) {
		int value=array[index];
		//printf("\n index is %d and  value is %d ", index, value);
	
		TreeNode* node=new TreeNode();
		node->value=array[index];		
		
		index++;
		if(index<length){
			node->left=CreateBFSFromPreOrderArray(array, length, index, min, value);
			node->right=CreateBFSFromPreOrderArray(array, length, index,value, max );			
		}
		
		
		return node;
	}
	else {
		return NULL;
	}
}

int main(int argc, char *argv[]) {
	int a[]={1,2,3,4,5};
	int length=sizeof(a)/sizeof(*a);
	TreeNode* root=CreateTreeFromArray(a,0, length-1 );
	printf("\n In Order Print: ");
	InOrderPrint(root);
	printf("\n Pre Order Print: ");
	PreOrderPrint(root);
	int preOrderArray[]={3,1,2,4,5};
	
	int index=0;
	TreeNode* newRoot=CreateBFSFromPreOrderArray( preOrderArray, length, index,INT_MIN, INT_MAX);
	printf("\n In Order Print: ");
	InOrderPrint(newRoot);
	return 0;
}