#include <iostream>
#include <vector>

using namespace std;


struct TreeNode {
      int val;
      TreeNode *left;
      TreeNode *right;
      TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 };


//create a tree 
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
  root->left->left->left->right=new TreeNode(78);
  return root;
}


void getTreePathRecursive(TreeNode* root, vector< vector<TreeNode*> >& paths, vector<TreeNode*> & path,  int& sum, int target){
	
	if(NULL==root)
		return; 

	sum +=root->val;
	//cout<<sum<<endl;
	path.push_back(root);


	if(sum>target) // do not add path
		return;

	if(sum==target){
		cout<<"get path"<<endl;
		paths.push_back(path);
		return;
	}	


	getTreePathRecursive(root->left, paths, path, sum, target);

	//cout<<sum<<endl;
	//leftTree
	//vector<TreeNode*> leftTreePath; int leftTreeSum=0; 
	//getTreePathRecursive(root->left, paths, leftTreePath, leftTreeSum, target);

	getTreePathRecursive(root->right, paths, path, sum, target);
	//rightTree
	//vector<TreeNode*> rightTreePath; int rightTreeSum=0;
	//getTreePathRecursive(root->right, paths, rightTreePath, rightTreeSum, target);

}



vector< vector<TreeNode*> > getTreePath(TreeNode* root, int target){
	
	vector< vector<TreeNode*> > paths;	
	vector<TreeNode*> path;
	int sum=0, leftSum=0, rightSum=0;
	getTreePathRecursive(root, paths, path, sum, target);
	return paths;
}


void printPath(const vector<TreeNode*>&  path){
	for (auto& node : path )
	{
		cout<<node->val<<endl;
	}
}

int main(int argc, char const *argv[])
{

	TreeNode* root=createTree();
	int target=137;
	vector< vector<TreeNode*> > paths=getTreePath(root, target);

	for (auto& path : paths )
	{
		cout<<"print path ";
		printPath(path);
		cout<<endl;
	}

	return 0;
}