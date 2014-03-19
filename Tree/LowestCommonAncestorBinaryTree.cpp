#include <iostream>
#include <cstdio>
#include <cassert>
#include <cassert>

using namespace std;

typedef	struct treeNode
{
	int value;
	struct treeNode* left;
	struct treeNode* right;
} TreeNode;


TreeNode* MakeTreeFromArray(int* a, int start, int end){
	if(start<=end)	{
		int middle=(start+end)/2;
		TreeNode* treeNode=new TreeNode();
		treeNode->value=a[middle];
		treeNode->left=MakeTreeFromArray(a, start, middle-1);
		treeNode->right=MakeTreeFromArray(a, middle+1, end);
		return treeNode;
	}
	else {
		return 0;
	}
}

void InOrderTravel(TreeNode* root){
	if(root!=0){
		InOrderTravel(root->left);
		printf("%d\t", root->value);
		InOrderTravel(root->right);		
	}
}

const TreeNode* getNode(const TreeNode* root, int value){
	if(NULL==root) return NULL;
	if(value==root->value) return root;
	const TreeNode* leftChild= getNode(root->left, value );
	if(leftChild) return leftChild;
	const TreeNode* rightChild=getNode(root->right, value);
	if(rightChild) return rightChild;

	return NULL;
}

const TreeNode* getLCA(const TreeNode* root, const TreeNode* left, const TreeNode* right){
	if(NULL==root) return NULL;
	if(root==left || root==right)
		return root;
	const TreeNode* leftLca=getLCA(root->left, left, right);
	const TreeNode* rightLca=getLCA(root->right, left, right);
	if(leftLca && rightLca) return root;
	return leftLca!=NULL? leftLca : rightLca;
}



const TreeNode* getLowestCommonAncestor(const TreeNode* root, int leftValue, int rightValue){
	const TreeNode* leftNode=getNode(root, leftValue);
	cout<<"left value : "<<leftNode->value<<endl;
	const TreeNode* rightNode=getNode(root, rightValue);
	return getLCA(root, leftNode, rightNode);
			
}

int main(int argc, char const *argv[]){

	int a[]={1,2,3,4,5,6,7,8,9,10};
	int length=sizeof(a)/sizeof(*a);
	printf("The lenght of the array is %d \n", length);
	TreeNode* root=MakeTreeFromArray(a,0,length-1);
	printf("print tree with root value %d\n", root->value);
	InOrderTravel(root);
	
	assert(5==getLowestCommonAncestor(root, 3, 8)->value);
	assert(2==getLowestCommonAncestor(root, 1, 3)->value);
	assert(3==getLowestCommonAncestor(root, 3, 4)->value);
	
	return 0;
}