#include <stdio.h>

typedef struct treeNode
{
	int value;
	struct treeNode* leftChild;
	struct treeNode* rightChild;
} TreeNode;

TreeNode* MakeTree(int* a, int left, int right){
	if(left>right)
		return 0;
	int middle=left+ (right-left)/2;
	TreeNode* treeNode=malloc(sizeof(TreeNode));
	treeNode->value=a[middle];
	treeNode->leftChild=MakeTree(a, left, middle-1);
	treeNode->rightChild=MakeTree(a, middle+1, right);
	return treeNode;
}

void InOrderPrint(TreeNode* root){
	if(root!=0)
	{
		InOrderPrint(root->leftChild);
		printf("%d\n", root->value);
		InOrderPrint(root->rightChild);
	}
}

int main(int argc, char *argv[]) {
	//int a[]={1,2,3,4,5,6,7,8,10};
	int a[]={1};
	int size=sizeof(a)/sizeof(*a);
	TreeNode* treeNode=MakeTree(a,0,size-1);
	InOrderPrint(treeNode);
}

