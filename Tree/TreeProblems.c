#include <stdio.h>


typedef struct tree{
	int value;
	struct tree* leftChild;
	struct tree* rightChild;
	struct tree* rightSibling;
} TreeNode;


typedef struct stackNode{
	TreeNode* node;
	struct stackNode* next;
} StackNode;

TreeNode* pre=NULL;

void Push(StackNode** stackHead, TreeNode* treeNode){
	StackNode* newNode=malloc(sizeof(StackNode));
	newNode->node=treeNode;
	newNode->next=0;
	if(*stackHead==0){
		*stackHead=newNode;
	}
	else {
		newNode->next=*stackHead;
		*stackHead=newNode;
	}
}

TreeNode* Pop(StackNode** stackHead){
	if(*stackHead==0){
		return 0;
	}
	else {
		StackNode* stackHeadNode=*stackHead;
		TreeNode* treeNode=stackHeadNode->node;
		free(stackHeadNode);
		*stackHead=(*stackHead)->next;
		return treeNode;
	}
}


TreeNode* CreateTreeFromArray(int* array, int length, int index){
	TreeNode* node=0;
	if(index<length){
		node=(TreeNode*)malloc(sizeof(TreeNode));
		node->value=array[index];
		int left=2*index +1;
		int right=2*index +2;
		node->leftChild=CreateTreeFromArray(array, length, left);
		node->rightChild=CreateTreeFromArray(array, length,right);
	}
	return node;
};

void ConnectRightSibling(TreeNode* node){
	if(node==0){
		return;
	}
	if(node->leftChild){
		node->leftChild->rightSibling=node->rightChild;
	}		
	if(node->rightChild){
		if(node->rightSibling){
			node->rightChild->rightSibling=node->rightSibling->leftChild;
		}
		else {
			node->rightChild->rightSibling=0;
		}
	}
	ConnectRightSibling(node->leftChild);
	ConnectRightSibling(node->rightChild);	
}





int main(int argc, char *argv[]) {
	int a[]={1,2,3,4,5,6,7};
	TreeNode* root=CreateTreeFromArray(a,7,0);
	//printf("\n Pre Order Travel ");
	//PreOrderTravel(root);
	//printf("\n Connect right sibling");
	//ConnectRightSibling(root);
	//PrintRightSibling(root);
	//printf("\n Pre Order Travel NonRecursive ");
	//PreOrderNonRecursive(root);
};