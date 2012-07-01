//http://www.geeksforgeeks.org/archives/6633
//Inorder sequence: D B E A F C
//Preorder sequence: A B D E C F
#include <stdio.h>
#include <stdlib.h>

typedef struct node{
	char value;
	struct node* left;
	struct node* right;
} Node;

int FindPositionOf(const char* inOrder, int length, char lookupChar){
	int position=-1;
	for (int i=0; i<length; i++) {
		if(inOrder[i]==lookupChar){
			position=i;
			break;
		}
	}
	return position;
}


Node* CreateTreeFromPreInOrder(char inOrder[], char preOrder[], int length){
	printf("length is %d \n", length);
	if (length==0) {
		return NULL;
	}
	else if(length==1){
		Node* node=malloc(sizeof(Node));
		node->value=preOrder[0];
		node->left=NULL;
		node->right=NULL;
		return node;
	}else {
		char preOrderChar=preOrder[0];
		int posOfCharInOrder=FindPositionOf(inOrder, length,preOrderChar);
		printf("position : %d\t", posOfCharInOrder);
		if(posOfCharInOrder>=0){
			Node* node=malloc(sizeof(Node));			node->value=preOrderChar;
			node->left=CreateTreeFromPreInOrder(inOrder, preOrder+1, posOfCharInOrder);
			int rightPosition=posOfCharInOrder+1;
			node->right=CreateTreeFromPreInOrder(inOrder+rightPosition, preOrder+rightPosition, length-rightPosition);
			return node;			
		}
	}
}

void InOrderTravel(Node* root){
	if(root!=NULL){
		InOrderTravel(root->left);
		printf("%c\t", root->value);
		InOrderTravel(root->right);
	}
}

void PreOrderTravel(Node* root){
	if(root!=NULL){
		printf("%c\t", root->value);
		PreOrderTravel(root->left);
		PreOrderTravel(root->right);
	}
}

int main(int argc, char *argv[]) {
	char inOrder[]={'D','B','E','A','F','C'};
	char preOrder[]={'A','B','D','E','C','F'};
	int length=sizeof(inOrder)/sizeof(*inOrder);
	Node* root=CreateTreeFromPreInOrder(inOrder,preOrder,length);
	printf("\n In Order Travel : ");
	InOrderTravel(root);
	printf("\n Pre Order Travel : ");
	PreOrderTravel(root);
}