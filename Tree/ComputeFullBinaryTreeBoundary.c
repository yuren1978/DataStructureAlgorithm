#include <cstdio>
#include <iostream>

using namespace std;

struct TreeNode {
  TreeNode *left, *right;
  int data;
  TreeNode(int val) : left(NULL), right(NULL), data(val) { }
};



TreeNode* createFullBinaryTree(){
    TreeNode* root=new TreeNode(45);
    //level 2
    root->left=new TreeNode(22);
    root->right=new TreeNode(70);
    //level 3
    root->left->left=new TreeNode(15);
    root->left->right=new TreeNode(27);
    root->right->left=new TreeNode(60);
    root->right->right=new TreeNode(80);
    //level 4
    root->left->left->left=new TreeNode(151);
	root->left->left->right=new TreeNode(152);

	root->left->right->left=new TreeNode(271);
	root->left->right->right=new TreeNode(272);

	root->right->left->left=new TreeNode(601);
	root->right->left->right=new TreeNode(602);

    root->right->right->left=new TreeNode(801);
    root->right->right->right=new TreeNode(802);


    return root;
}

bool isRoot(const TreeNode* node){
	return NULL==node->left && NULL==node->right;
}





void printLeftBoundaryNode(const TreeNode* root, bool print){

	if(NULL==root)
		return;
	
	if(print || isRoot(root)){
		cout<<root->data<<endl;
	}

	printLeftBoundaryNode(root->left,  print);
	printLeftBoundaryNode(root->right, false);
	
}


int main(int argc, char *argv[]) {
	TreeNode* root=createFullBinaryTree();
	cout<<root->data<<endl;
	printLeftBoundaryNode(root->left,true);
	printLeftBoundaryNode(root->right,true);
}