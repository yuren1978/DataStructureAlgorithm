#include <stdio.h>
#include <stdlib.h>

typdef struct node {
	int value;
	struct node* next;
} Node;

Node* CreateList(int[] a, int start, end){
	
}

Node* FindNodeInListOne(Node* head, int position){
	
}

void ConnectLastNode(Node* head, Node* connectingNode){
	
}



int main(int argc, char *argv[]) {
	int a[]={1,2,3,4,5,6,7,8,9,10};
	int length1=sizeof(a)/sizeof(*a);
	Node* head1=CreateList(a,0, length-1);
	Node* thirdNodeInListOne=FindNodeInListOne(head1, 3);
	
	int b[]={11,12,13};
	int length2=sizeof(b)/sizeof(*b);
	Node* head2=CreateList(b,0, length2);
	
	ConnectLastNode(head2, thirdNodeInListOne);
	
}