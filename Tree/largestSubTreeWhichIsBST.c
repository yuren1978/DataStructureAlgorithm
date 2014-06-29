//http://www.leetcode.com/2010/11/largest-binary-search-tree-bst-in.html
//Given a binary tree, find the largest subtree which is a Binary Search Tree (BST),
// where largest means subtree with largest number of nodes in it.
#include <cstdio>
#include <cassert>
#include <iostream>

using namespace std;

struct TreeNode {
  TreeNode *left, *right;
  int data;
  TreeNode(int val) : left(NULL), right(NULL), data(val) { }
};


//int noOfNodes;
 
TreeNode* findLargestBSTSubtree(TreeNode *root) {

    static int noOfNodes;

    if (!root) {
        noOfNodes = 0;
        return root;
    }
    
    //get left nodes.
    TreeNode* leftLargestBST = findLargestBSTSubtree(root->left);
    int leftSubtreeNodes = noOfNodes;
    
    //get right nodes.
    TreeNode* rightLargestBST = findLargestBSTSubtree(root->right);
    int rightSubtreeNodes = noOfNodes;
    
    if (leftLargestBST == root->left && rightLargestBST == root->right) {
        
        if ( (!root->left || root->left->data<= root->data) && (!root->right || root->right->data >= root->data) ) {
            noOfNodes = leftSubtreeNodes + rightSubtreeNodes + 1;
            cout<<noOfNodes<<endl;
            return root;
        }    
    }


    if (leftSubtreeNodes > rightSubtreeNodes) {
        noOfNodes = leftSubtreeNodes;
        return leftLargestBST;
    } else {
        noOfNodes = rightSubtreeNodes;
        return rightLargestBST;
    }
}

TreeNode* createTree(){
     TreeNode* root=new TreeNode(10);
      //level 2
      root->left=new TreeNode(5);
      root->right=new TreeNode(15);
      //level 3
      root->left->left=new TreeNode(1);
      root->left->right=new TreeNode(8);

      root->right->right=new TreeNode(7);

      return root;
}


int main(int argc, char *argv[]) {
	TreeNode* root=createTree();
    TreeNode* largetTree=findLargestBSTSubtree(root);
    cout<<largetTree->data<<endl;
    //cout<<noOfNodes<<endl;
    assert(5==largetTree->data);
    assert(1==largetTree->left->data);
    assert(8==largetTree->right->data);
}