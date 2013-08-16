//http://zhedahht.blog.163.com/blog/static/25411174201011445550396/
//http://www.youtube.com/watch?v=J29eAoniIsw
#include <iostream>
#include <cassert>

using namespace std;

typedef struct treeNode{
	int value;
	struct treeNode* left;
	struct treeNode* right;
} TreeNode;

bool HasSubTree(const TreeNode* parentTree, const TreeNode* childTree){
	if(parentTree==NULL)
		return false;
	
	if(childTree==NULL)
		return true;
		
	if(parentTree->value==childTree->value)	{
		return HasSubTree(parentTree->left, childTree->left)
			&& HasSubTree(parentTree->right, childTree->right);
		
	}else {
		return HasSubTree(parentTree->left, childTree)
			|| HasSubTree(parentTree->right, childTree);
	}	
}

TreeNode* MakeTreeNode(int value){
	TreeNode* node=new TreeNode();
	node->value=value;
	return node;
}

void PreOrderPrint(const TreeNode* root){
	if(root!=NULL){
		cout<<root->value<<" ";
		PreOrderPrint(root->left);
		PreOrderPrint(root->right);			
	}
}

int main(int argc, char *argv[]) {
	TreeNode* root1=MakeTreeNode(1);
	root1->left=MakeTreeNode(2);
	root1->left->left=MakeTreeNode(4);
	root1->left->right=MakeTreeNode(5);
	root1->right=MakeTreeNode(3);
	root1->right->left=MakeTreeNode(6);
	root1->right->right=MakeTreeNode(7);	
	PreOrderPrint(root1); cout<<endl;
	
	TreeNode* root2=MakeTreeNode(1);
	root2->left=MakeTreeNode(2);
	root2->right=MakeTreeNode(3);
	
	assert(HasSubTree(root1, root2));
	
}