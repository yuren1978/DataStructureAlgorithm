#include <iostream>
#include <vector>

using namespace std;


struct TreeNode {
      int val;
      TreeNode *left;
      TreeNode *right;
      TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

TreeNode* reverseTree(TreeNode* root,  TreeNode* & rotateRoot){
	if(NULL==root->left && NULL==root->right){
		rotateRoot=root;
		return root;
	}

	TreeNode* leftRoot=NULL;
	
	TreeNode* leftTail=reverseTree(root->left, leftRoot);
	if(root->right)
		leftTail->left=root->right;
	leftTail->right=root;

	rotateRoot=leftRoot;
	rotateTail=root;
}


TreeNode* reverseTree(TreeNode* root){
	if( NULL==root|| (NULL==root->left && NULL==root->right) )
		return root;

	TreeNode* leftRoot=NULL;
	reverseTree(root, leftRoot);
	return leftRoot;
}