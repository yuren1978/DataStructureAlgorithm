#include <fstream>
#include <iostream>
#include <deque>
#include <iomanip>
#include <sstream>
#include <string>
#include <cmath>

using namespace std;

struct BinaryTree {
  BinaryTree *left, *right;
  int data;
  BinaryTree(int val) : left(NULL), right(NULL), data(val) { }
};

// Find the maximum height of the binary tree


BinaryTree* CreateTreeFromArray(int* array, int start, int end){
	if(start>end){
		return NULL;
	}
	int middle=(start+end)/2;
	BinaryTree* node=new BinaryTree(array[middle]);
	node->left=CreateTreeFromArray(array, start, middle-1);
	node->right=CreateTreeFromArray(array, middle+1, end);
	return node;
}



void PrintTreeByLevel(BinaryTree* root, int level){
	if(root==NULL) return;
	if(level==0){
		cout<<root->data<<" ";
	}
	else {
		PrintTreeByLevel(root->left,level-1);
		PrintTreeByLevel(root->right,level-1);
	}
}


int maxHeight(BinaryTree* root){
  if(NULL==root)
      return 0;

   int leftHeight=maxHeight(root->left);
   int rightHeight =maxHeight(root->right);

   return leftHeight>rightHeight? 1+leftHeight: 1+rightHeight;
}

int main(int argc, char *argv[]) {
		int a[]={1,2,3,4,5,6,7,8,9};
		BinaryTree* root=CreateTreeFromArray(a,0,8);
		//printPretty(root,0,1, cout);
		int height=maxHeight(root);
		for (int level=0; level<height; level++) {
			PrintTreeByLevel(root, level);
			cout<<endl;
		}
		
}