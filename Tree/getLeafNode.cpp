#include <fstream>
#include <iostream>
#include <deque>
#include <iomanip>
#include <string>
#include <cmath>

using namespace std;

struct TreeNode {
      int val;
      TreeNode *left;
      TreeNode *right;
      TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 };


int pow(int base, int n){
    int result=1;
    for(int i=0; i<n; i++){
        result=result*base; 
    }
    return result;
}

void getLeafNode(TreeNode* root, int& leafNode, int level, int depth){
	if(NULL==root) return;
	if(level==depth){
		leafNode++;
		return;
	}
	getLeafNode(root->left, leafNode, level+1, depth);
	getLeafNode(root->right, leafNode, level+1, depth);

}

int getNonLeafNode(TreeNode* root, int& depth){
	TreeNode* leftChild=root;
	while(leftChild!=NULL){
		depth++;
		leftChild=leftChild->left;
	}
	int nonRootNode=pow(2, depth-1)-1;
    return nonRootNode;
}

int main(){
	TreeNode* root=new TreeNode(1);
	root->left=new TreeNode(2);
	root->right=new TreeNode(3);
	root->left->left=new TreeNode(4);
	root->left->right=new TreeNode(5);
	int depth=0;
	int nonLeafNode=getNonLeafNode(root, depth);
	int leafNode=0;
	getLeafNode(root, leafNode, 1, depth);
	cout<<leafNode<<endl;
	cout<<nonLeafNode<<endl;
}