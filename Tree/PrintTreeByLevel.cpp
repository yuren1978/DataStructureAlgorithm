#include <fstream>
#include <utility>
#include <iostream>
#include <deque>
#include <queue>
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


void PrintTreeByLevelQueue(BinaryTree* root){
	if(NULL==root) return;

	queue<pair<BinaryTree*,int> > q;
	q.push(make_pair(root,0));

	int level=0;
	cout<<level<<" : ";
	while(!q.empty()){
		auto& top=q.front();
		if(top.second!=level){ //new level
			level=top.second;
			cout<<endl;
			cout<<level<<" : ";
		}
		cout<<" "<<top.first->data;
		q.pop();
		if(top.first->left){
			q.push(make_pair(top.first->left,top.second+1));
		}
		if(top.first->right){
			q.push(make_pair(top.first->right,top.second+1));
		}		
	}
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
		PrintTreeByLevelQueue(root);
		//printPretty(root,0,1, cout);
		//int height=maxHeight(root);
		// for (int level=0; level<height; level++) {
		// 	cout<<level<<": ";
		// 	PrintTreeByLevel(root, level);
		// 	cout<<endl;
		// }
		
}