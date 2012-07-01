#include <stdio.h>
// 1,2,3,4,5,6,7,8,9,10
//			   5
//		2			8
//   1		3 	6		9
//       4			7   	10
typedef struct node{
	int value;
	struct node* left;
	struct node* right;
	struct node* next;
} Node;

Node* CreateTreeFromArray(int* a, int start, int end)
{
	if(start<=end)
	{
		int middle=(start+end)/2;
		Node* node=malloc(sizeof(Node));
		node->value=a[middle];	
		node->left=	CreateTreeFromArray(a, start,middle-1);
		node->right=CreateTreeFromArray(a, middle+1,end);
		node->next=0;
		return node;
	}
	else {
		return 0;
	}
}

void PopulateNextNodeInTree(Node* root){
	if(root!=0){		
			if(root->left!=0){
				root->left->next=root->right;				}
			if(root->right!=0){
				if(root->next!=0){
					root->right->next=root->next->left!=0?root->next->left:root->next->right;
				}
			}
			PopulateNextNodeInTree(root->left);
			PopulateNextNodeInTree(root->right);
	}
} 

void PreOrderPrintNext(Node* root){
	if(root!=0){
		//printf("%d ", root->value);
		printf("%d right value %d\n", root->value, root->next!=0?root->next->value:-1);
		PreOrderPrintNext(root->left);
		PreOrderPrintNext(root->right);
	}
} 

int main(int argc, char *argv[]) {
	int a[]={1,2,3,4,5,6,7,8,9,10};
	int length=sizeof(a)/sizeof(*a);
	Node* root=CreateTreeFromArray(a,0,length-1);
	PreOrderPrintNext(root);
	PopulateNextNodeInTree(root);
	PreOrderPrintNext(root);
}