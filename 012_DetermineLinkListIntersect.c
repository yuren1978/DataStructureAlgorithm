#include <stdio.h>
#include <stdlib.h>

typedef struct node {
	int value;
	struct node* next;
} Node;

void PrintList(Node* head){
	Node* temp=head;
	while(temp!=0){
		printf("%d\t", temp->value);
		temp=temp->next;
	}
	printf("\n");
}

Node* CreateList(int* a, int length){
	Node* head=NULL;
	for (int index=0; index<length; index++) {
		Node* node=malloc(sizeof(Node));
		node->value=a[index];
		if(head==NULL){
			head=node;
			head->next=NULL;
		}
		else {
			node->next=head;
			head=node;
		}
	}
	return head;
}

Node* FindNodeInListOne(Node* head, int position){
	Node* temp=head;
	int count=0;
	while (temp->next!=NULL) {
		if(count++==position){
			break;		
		}	
		temp=temp->next;	
	}
	return temp;
}

void ConnectLastNode(Node* head, Node* connectingNode){
	Node* temp=head;
	while (temp->next!=NULL) {
		temp=temp->next;
	}
	temp->next=connectingNode;
}



int main(int argc, char *argv[]) {
	int a[]={10,9,8,7,6,5,4,3,2,1};
	int length1=sizeof(a)/sizeof(*a);
	Node* head1=CreateList(a, length1);
	Node* thirdNodeInListOne=FindNodeInListOne(head1, 3);
	int b[]={15,14,13,12,11};
	int length2=sizeof(b)/sizeof(*b);
	Node* head2=CreateList(b,length2);	
	ConnectLastNode(head2, thirdNodeInListOne);
	PrintList(head1);
	PrintList(head2);
}