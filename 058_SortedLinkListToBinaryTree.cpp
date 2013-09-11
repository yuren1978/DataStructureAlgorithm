#include <cstdio>
#include <cstdlib>
#include <fstream>
#include <iostream>
#include <deque>
#include <iomanip>
#include <sstream>
#include <string>
#include <cmath>

using namespace std;

typedef struct node {
	int value;
	struct node* next;
} Node;

struct BinaryTree{
	int data;
	struct BinaryTree* left;
	struct BinaryTree* right;
};

// Find the maximum height of the binary tree
int maxHeight(BinaryTree *p) {
  if (!p) return 0;
  int leftHeight = maxHeight(p->left);
  int rightHeight = maxHeight(p->right);
  return (leftHeight > rightHeight) ? leftHeight + 1: rightHeight + 1;
}

// Convert an integer value to string
string intToString(int val) {
  ostringstream ss;
  ss << val;
  return ss.str();
}

// Print the arm branches (eg, /    \ ) on a line
void printBranches(int branchLen, int nodeSpaceLen, int startLen, int nodesInThisLevel, const deque<BinaryTree*>& nodesQueue, ostream& out) {
  deque<BinaryTree*>::const_iterator iter = nodesQueue.begin();
  for (int i = 0; i < nodesInThisLevel / 2; i++) {  
    out << ((i == 0) ? setw(startLen-1) : setw(nodeSpaceLen-2)) << "" << ((*iter++) ? "/" : " ");
    out << setw(2*branchLen+2) << "" << ((*iter++) ? "\\" : " ");
  }
  out << endl;
}

// Print the branches and node (eg, ___10___ )
void printNodes(int branchLen, int nodeSpaceLen, int startLen, int nodesInThisLevel, const deque<BinaryTree*>& nodesQueue, ostream& out) {
  deque<BinaryTree*>::const_iterator iter = nodesQueue.begin();
  for (int i = 0; i < nodesInThisLevel; i++, iter++) {
    out << ((i == 0) ? setw(startLen) : setw(nodeSpaceLen)) << "" << ((*iter && (*iter)->left) ? setfill('_') : setfill(' '));
    out << setw(branchLen+2) << ((*iter) ? intToString((*iter)->data) : "");
    out << ((*iter && (*iter)->right) ? setfill('_') : setfill(' ')) << setw(branchLen) << "" << setfill(' ');
  }
  out << endl;
}

// Print the leaves only (just for the bottom row)
void printLeaves(int indentSpace, int level, int nodesInThisLevel, const deque<BinaryTree*>& nodesQueue, ostream& out) {
  deque<BinaryTree*>::const_iterator iter = nodesQueue.begin();
  for (int i = 0; i < nodesInThisLevel; i++, iter++) {
    out << ((i == 0) ? setw(indentSpace+2) : setw(2*level+2)) << ((*iter) ? intToString((*iter)->data) : "");
  }
  out << endl;
}

// Pretty formatting of a binary tree to the output stream
// @ param
// level  Control how wide you want the tree to sparse (eg, level 1 has the minimum space between nodes, while level 2 has a larger space between nodes)
// indentSpace  Change this to add some indent space to the left (eg, indentSpace of 0 means the lowest level of the left node will stick to the left margin)
void printPretty(BinaryTree *root, int level, int indentSpace, ostream& out) {
  int h = maxHeight(root);
  int nodesInThisLevel = 1;

  int branchLen = 2*((int)pow(2.0,h)-1) - (3-level)*(int)pow(2.0,h-1);  // eq of the length of branch for each node of each level
  int nodeSpaceLen = 2 + (level+1)*(int)pow(2.0,h);  // distance between left neighbor node's right arm and right neighbor node's left arm
  int startLen = branchLen + (3-level) + indentSpace;  // starting space to the first node to print of each level (for the left most node of each level only)
    
  deque<BinaryTree*> nodesQueue;
  nodesQueue.push_back(root);
  for (int r = 1; r < h; r++) {
    printBranches(branchLen, nodeSpaceLen, startLen, nodesInThisLevel, nodesQueue, out);
    branchLen = branchLen/2 - 1;
    nodeSpaceLen = nodeSpaceLen/2 + 1;
    startLen = branchLen + (3-level) + indentSpace;
    printNodes(branchLen, nodeSpaceLen, startLen, nodesInThisLevel, nodesQueue, out);

    for (int i = 0; i < nodesInThisLevel; i++) {
      BinaryTree *currNode = nodesQueue.front();
      nodesQueue.pop_front();
      if (currNode) {
	      nodesQueue.push_back(currNode->left);
	      nodesQueue.push_back(currNode->right);
      } else {
        nodesQueue.push_back(NULL);
        nodesQueue.push_back(NULL);
      }
    }
    nodesInThisLevel *= 2;
  }
  printBranches(branchLen, nodeSpaceLen, startLen, nodesInThisLevel, nodesQueue, out);
  printLeaves(indentSpace, level, nodesInThisLevel, nodesQueue, out);
}

Node* CreateNodeFromList(int* a, int length){
	Node* head=0;
	for (int index=0; index<length; index++) {
		Node* newNode=new Node();
		newNode->value=a[index];
		if(head==0){
			newNode->next=0;
			head=newNode;
		}
		else {
			newNode->next=head;
			head=newNode;
		}
	}
	return head;
}

void PrintList(Node* head){
	printf("Print List : ");
	Node* travelHead=head;
	while (travelHead!=0) {
		printf("%d \t ", travelHead->value);
		travelHead=travelHead->next;
	}
	
	printf("\n");
}


Node* SplitList(Node* head)
{
	Node* fast=head;
	Node* slow=head;
	Node* preSlow=NULL;
	while(fast!=0 && fast->next!=0)
	{
		fast=fast->next->next;
		preSlow=slow;
		slow=slow->next;
	}
	if(preSlow!=NULL)
		preSlow->next=NULL;
	return slow;
}



BinaryTree* SortedLinkListToBinaryTree(Node* head){
	if(head==NULL)
		return NULL;
	else if (head->next==NULL) {
		BinaryTree* root=new BinaryTree();
		root->data=head->value;
		root->left=NULL;
		root->right=NULL;
		return root;
	}	
	else {
		Node* middle=SplitList(head);
		BinaryTree* root=new BinaryTree();
		root->data=middle->value;
		root->left=SortedLinkListToBinaryTree(head);
		root->right=SortedLinkListToBinaryTree(middle->next);
		return root;
	}	
	
}

int main(int argc, char *argv[]) {
	int a[]={10,9,8,7,6,5,4,3,2,1};
	int length=sizeof(a)/sizeof(*a);
	Node* head=CreateNodeFromList(a, length);
	PrintList(head);
	//Node* middle=SplitList(head);
	BinaryTree* root=SortedLinkListToBinaryTree(head);
	printPretty(root, 1, 0, cout);
	//PrintList(head);
	//PrintList(middle);
}