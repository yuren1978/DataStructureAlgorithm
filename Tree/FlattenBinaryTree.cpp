#include <iostream>

using namespace std;

struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};


void flattenToHeadTail(TreeNode* root, TreeNode* & head, TreeNode* & tail){
	if(root==NULL){
		head=NULL;
		tail=NULL;
		return;
	}
	
	TreeNode* leftHead=NULL;
	TreeNode* leftTail=NULL;
	TreeNode* rightHead=NULL;
	TreeNode* rightTail=NULL;
	
	flattenToHeadTail(root->right, rightHead, rightTail);
	flattenToHeadTail(root->left, leftHead, leftTail);
	
	root->right=leftHead!=NULL?leftHead:rightHead;
	root->left=NULL;


	if(leftTail!=NULL){
		leftTail->left=NULL;
		leftTail->right=rightHead;		
	}

	
	head=root;
	tail=rightTail;
	if(tail==NULL){
		tail=leftTail;
	}
	if(tail==NULL){
		tail=head;
	}		
}


void flatten(TreeNode *root) {
	if(root==NULL){
		return;
	}	
	TreeNode* head=NULL;
	TreeNode* tail=NULL;	
	flattenToHeadTail(root, head, tail);	
	root=head;
	tail->right=NULL;
	return;
}


void printList(TreeNode* head){
	TreeNode* temp=head;
	while (temp!=NULL) {
		cout<<temp->val;
		temp=temp->right;
	}	
	cout<<endl;
}

int main(int argc, char *argv[]) {
	TreeNode* root=new TreeNode(1);
	root->left=new TreeNode(2);
	root->left->left=new TreeNode(4);
	root->right=new TreeNode(2);
	flatten(root);
	printList(root);
}