#include <cstdlib>
#include <cstdio>
#include <iostream>

using namespace std;

struct Node {
      int val;
      Node *left;
      Node *right;
      Node(int x) : val(x), left(NULL), right(NULL) {}
 };


Node* ConvertArrayToTree(int* a, int start, int end){
	if(start<=end){
		int middle=(start+end)/2;
		Node* node=new Node(a[middle]);
		node->left=ConvertArrayToTree(a, start, middle-1);
		node->right=ConvertArrayToTree(a, middle+1,end);
		return node;			
	}
	else{
		return 0;
	}
}

void InOrderPrint(Node* root){
	if(root!=0){
		InOrderPrint(root->left);
		printf("%d\t", root->val);
		InOrderPrint(root->right);
	}
}

void TreeToCircularDoubleLinkList(Node* node, Node* & head){
	if(node==NULL)
		return;

	// Initialize previously visited node as NULL. This is
    // static so that the same value is accessible in all recursive
    // calls
    static Node* prev = NULL;

	TreeToCircularDoubleLinkList(node->left, head);

	if(prev==NULL)
		head=node;
	else{
		node->left=prev;
		prev->right=node;
	}

	prev=node;

	TreeToCircularDoubleLinkList(node->right, head);			
}


void PrintDoubleLinkList(Node* head){
	while(NULL!=head){
		cout<<head->val;
		head=head->right;
	}
	cout<<endl;
}

int main(int argc, char const *argv[])
{
	int a[]={1,2,3,4,5,6,7,8,9,10};
	int length=sizeof(a)/sizeof(*a);
	Node* root=ConvertArrayToTree(a,0, length-1);
	InOrderPrint(root);
	printf("end of printing\n");
	Node* head=0;	
	TreeToCircularDoubleLinkList(root,head);
	PrintDoubleLinkList(head);
	return 0;
}