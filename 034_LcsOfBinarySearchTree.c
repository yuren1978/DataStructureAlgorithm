#include <stdio.h>

typedef struct	node{
	int value;
	struct node* left;
	struct node* right; 
} Node;

Node* CreateBFSFromArray(int* a, int start, int end)
{
	if(start<=end){
		int middle=(start+end)/2;
		Node* newNode=malloc(sizeof(Node));
		newNode->value=a[middle];
		newNode->left=CreateBFSFromArray(a, start, middle-1);
		newNode->right=CreateBFSFromArray(a, middle+1, end);
		return newNode;		
	}
	else {
		return 0;
	}
}

void InOrderPrint(Node* root){
	if(root!=0){
		InOrderPrint(root->left);
		printf("%d\t", root->value);
		InOrderPrint(root->right);
	}
}

Node* LcsOfBinarySearchTree(Node* root, int leftValue, int rightValue){
	if(root->value >leftValue && root->value > rightValue ){
		return LcsOfBinarySearchTree(root->left, leftValue, rightValue);
	}
	else if (root->value <leftValue && root->value < rightValue) {
		return LcsOfBinarySearchTree(root->right, leftValue, rightValue);
	}
	else {
		return root;
	}	
}


int main(int argc, char *argv[]) {
	int a[]={1,2,3,4,5,6,7,8,9,10};
	int length=sizeof(a)/sizeof(*a);
	Node* root=CreateBFSFromArray(a,0,length-1);
	InOrderPrint(root);
	printf("\n");
	printf("Lcs Of %d and %d is %d\n", 3, 8,  LcsOfBinarySearchTree(root, 3, 8)->value );
	printf("Lcs Of %d and %d is %d\n", 1, 3,  LcsOfBinarySearchTree(root, 1, 3)->value );
	printf("Lcs Of %d and %d is %d\n", 3, 4,  LcsOfBinarySearchTree(root, 3, 4)->value );
	
}