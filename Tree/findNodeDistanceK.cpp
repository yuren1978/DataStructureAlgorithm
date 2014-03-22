#include <fstream>
#include <iostream>
#include <deque>
#include <iomanip>
#include <string>
#include <cmath>
#include <vector>
#include <stack>

using namespace std;

struct TreeNode {
      int val;
      TreeNode *left;
      TreeNode *right;
      TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

vector<TreeNode*> getChildAtDistanceK(const TreeNode* node, int distance){
	vector<TreeNode*> v;
	return v;	
}

vector<pair<TreeNode*, int>> getParentPath(const TreeNode* root, const TreeNode* target){
	vector<pair<TreeNode*, int>> s;
	return s;
}


vector<TreeNode*> getListOfNodesDistance(const TreeNode* root, const TreeNode* target, int distance){
	vector<TreeNode*> v;
	vector<TreeNode*> childVectors=getChildAtDistanceK(target, distance);
	for(auto& childVector: childVectors){
		v.push_back(childVector);
	}

	vector<pair<TreeNode*, int> > parentNodes=getParentPath(root, target);
	for(auto& parentNodePair : parentNodes){
		if(parentNodePair.second==distance){//add this parent
			v.push_back(parentNodePair.first);
		}
		else if(parentNodePair.second<distance){//search the other half of the tree
			vector<TreeNode*> childVectorsInTree=getChildAtDistanceK(target, distance-parentNodePair.second);
			for (auto& childNode : childVectorsInTree){
				v.push_back(childNode);		
			}
		}
	}
	return v;
}


TreeNode* createTree(){
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
  root->left->left->left=new TreeNode(8);
  root->left->left->right=new TreeNode(17);
  root->right->left->left=new TreeNode(75);
  root->right->right->right=new TreeNode(90);

  //leve 5
  root->left->left->left->left=new TreeNode(72);
  root->left->left->left->left=new TreeNode(78);
  return root;
}

int main(int argc, char const *argv[])
{
	TreeNode* root=createTree();
	TreeNode* startNode=root->right;
	cout<<startNode->val<<endl;


	return 0;
}
