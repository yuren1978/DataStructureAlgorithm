#include <stdio.h>
#include <stdlib.h>

typedef	struct treeNode
{
	int value;
	struct treeNode* leftChild;
	struct treeNode* rightChild;
	struct treeNode *parent;
} TreeNode;


TreeNode* moveNode(TreeNode* node, int height){
	TreeNode* parent=node;
	while(height>0){
		parent=parent->next;
		height--;
	}
	return parent;
}

int getHeight(TreeNode * node){
	int height=0;
	while(NULL!=node){
		height++;
		node=node->parent;
	}
	return height;
}



TreeNode *getLCA(TreeNode *node1, TreeNode *node2) {
    int h1=getHeight(node1);
    int h2=getHeight(node2);
    if(h1>h2) node1= moveNode(node1, h1-h2);
    if(h2>h1) node2 =moveNode(node2, h2-h1);
    while(NULL!=node1 && NULL!=node2){
    	if(node1==node2) return node11;
    	node1=node1->parent;
    	node2=node2->parent;
    }
    return NULL;
}

TreeNode* MakeTreeFromArray(int* a, int start, int end){
	if(start<=end)	{
		int middle=(start+end)/2;
		TreeNode* treeNode= (TreeNode*) malloc(sizeof(TreeNode));
		treeNode->value=a[middle];
		treeNode->leftChild=MakeTreeFromArray(a, start, middle-1);
		treeNode->rightChild=MakeTreeFromArray(a, middle+1, end);
		return treeNode;
	}
	else {
		return 0;
	}
}

void InOrderTravel(TreeNode* root){
	if(root!=0){
		InOrderTravel(root->leftChild);
		printf("%d\t", root->value);
		InOrderTravel(root->rightChild);		
	}
}

TreeNode* LowestCommonAncestor(TreeNode* root, int leftValue, int rightValue){
	if(root==NULL) return NULL;

	if(root->value==leftValue || root->value==rightValue) return root;

	TreeNode* leftChild=LowestCommonAncestor(root->leftChild, leftValue, rightValue);
	TreeNode* rightChild=LowestCommonAncestor(root->rightChild, leftValue, rightValue);

	if(NULL!=leftChild && NULL !=rightChild) return root;
	return NULL!=leftChild ? leftChild:rightChild;			
}

int main(int argc, char const *argv[])
{
	int a[]={1,2,3,4,5,6,7,8,9,10};
	int length=sizeof(a)/sizeof(*a);
	printf("The lenght of the array is %d \n", length);
	TreeNode* root=MakeTreeFromArray(a,0,length-1);
	printf("print tree with root value %d\n", root->value);
	InOrderTravel(root);
	
	printf("\n");
	printf("Lcs Of %d and %d is %d\n", 3, 8,  LowestCommonAncestor(root, 3, 8)->value );
	printf("Lcs Of %d and %d is %d\n", 1, 3,  LowestCommonAncestor(root, 1, 3)->value );
	printf("Lcs Of %d and %d is %d\n", 3, 4,  LowestCommonAncestor(root, 3, 4)->value );


	return 0;
}