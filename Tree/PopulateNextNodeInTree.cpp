#include <cstdio>
#include <queue>
using namespace std;
// 1,2,3,4,5,6,7,8,9,10
//			   5
//		2			8
//   1		3 	6		9
//       4			7   	10


struct TreeLinkNode{
	int value;
	TreeLinkNode* left;
	TreeLinkNode* right;
	TreeLinkNode* next;
	TreeLinkNode (int x): value(x),left(NULL), right(NULL), next(NULL){}
};



void PopulateNext(TreeLinkNode* root){
	 if(root==NULL) return;
	 deque<TreeLinkNode*> nodeQueue;
	 nodeQueue.push_back(root);	
	 
	 while(!nodeQueue.empty()){
	
			TreeLinkNode* node=nodeQueue.front();
					printf("current node value is %d\n", node->value);
		    		if(node->left!=NULL){
							nodeQueue.push_back(node->left);
				            if(node->right!=NULL){
				                node->left->next=node->right;
				            }
				            else{
				                TreeLinkNode* next=node->next;
				                while(next!=NULL && ( next->left==NULL && next->right==NULL ) ){
				                    next=next->next;                    
				                }
				                if(next!=NULL)
				                    node->left->next=next->left!=NULL?next->left:next->right;
				            }
				        }
				        
				        if(node->right!=NULL){
							nodeQueue.push_back(node->right);
				             TreeLinkNode* next=node->next;
				             while(next!=NULL && ( next->left==NULL && next->right==NULL ) ){
				                next=next->next;                    
				             }
				             if(next!=NULL){
				                 node->right->next=next->left!=NULL?next->left:next->right;
				             }
				        }
			nodeQueue.pop_front();
	}
	    	  
} 

void PreOrderPrintNext(TreeLinkNode* root){
	if(root!=0){
		printf("%d right value %d\n", root->value, root->next!=0?root->next->value:-1);
		PreOrderPrintNext(root->left);
		PreOrderPrintNext(root->right);
	}
} 

int main(int argc, char *argv[]) {
	TreeLinkNode* root=new TreeLinkNode(2);
	root->left=new TreeLinkNode(1);
	root->right=new TreeLinkNode(3);
	root->left->left=new TreeLinkNode(0);
	root->left->right=new TreeLinkNode(7);
	root->right->left=new TreeLinkNode(9);
	root->right->right=new TreeLinkNode(1);
	root->left->left->left=new TreeLinkNode(2);
	root->left->right->left=new TreeLinkNode(1);
	root->left->right->right=new TreeLinkNode(6);
	root->right->right->left=new TreeLinkNode(8);
	root->right->right->right=new TreeLinkNode(8);
	root->left->right->right->left=new TreeLinkNode(7);
	//int a[]={1,2,3,4,5,6,7,8,9,10};
	//int length=sizeof(a)/sizeof(*a);
	//TreeLinkNode* root=CreateTreeFromArray(a,0,length-1);
	//PreOrderPrintNext(root);
	PopulateNext(root);
	PreOrderPrintNext(root);
}