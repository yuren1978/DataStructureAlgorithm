/**
 * Definition for binary tree
*/

#include <iostream>
using namespace std;

  struct TreeNode {
      int val;
      TreeNode *left;
      TreeNode *right;
      TreeNode(int x) : val(x), left(NULL), right(NULL) {}
  };
 

int maxOutOfThree(int max, int leftMax, int rightMax){
    int threeMax=INT_MIN;
    if(max>threeMax){
        threeMax=max;
    }
    if(leftMax>max){
        threeMax=leftMax;
    }
    if(rightMax>max){
        threeMax=rightMax;
    }
    return threeMax;
}


int treeSum(TreeNode* root){
	if(root==NULL){
		return 0;
	}
	else {
		int leftTreeSum=treeSum(root->left);
		int rightTreeSum=treeSum(root->right);		return root->val+ (leftTreeSum>rightTreeSum?leftTreeSum:rightTreeSum);
	}
}
   

   int maxPathSum(TreeNode *root) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
       int max; 
        if(root==NULL){
        	max=INT_MIN;
    	}	
    	else {
    		int value=root->val;
    		int currentMax=value+treeSum(root->left)+treeSum(root->right);
			//cout<<currentMax<<endl;
    		int leftMax= maxPathSum(root->left);
    		int rightMax=maxPathSum(root->right);
    		max=maxOutOfThree(currentMax,leftMax,rightMax );
    	}		
        return max;
    }
   	
   
  


   
int main(int argc, char *argv[]) {
	TreeNode* treeNode=new TreeNode(2);
	treeNode->left=new TreeNode(-1);
	int maxPath=maxPathSum(treeNode);
	cout<<maxPath<<endl;
}   
   
