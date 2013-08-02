#include <cstdio>
#include <cstdlib>


typedef struct node
{
	int value;
	struct node* next;
} Node;

Node* MakeListFromArray(int* a, int start, int end){
	Node* head=0;
	for (int i=start; i<end; i++){
		Node* node=(Node*) malloc(sizeof(Node));
		node->value=a[i];
		if(head==0){
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

void PrintList(Node* head){
	printf("\n");
	Node* travelNode=head;
	while(travelNode!=NULL){
		printf("%d\t", travelNode->value);
		travelNode=travelNode->next;
	}
}

Node* ReverseList(Node* head){
	if(head==NULL || head->next==NULL)
		return head;

	Node* helper=(Node*) malloc(sizeof(Node));
	helper->next=head;

	Node* prev=helper; Node* current=head;

	while(current->next!=NULL){
		Node* temp=current->next;
		current->next=temp->next;
		temp->next=prev->next;
		prev->next=temp;
	}

	return helper->next;

}

int main(int argc, char const *argv[])
{
	int a[]={0,1,2};
	int length=sizeof(a)/sizeof(*a);
	Node* head= MakeListFromArray(a, 0, length);
	PrintList(head);
	Node* reverseHead=ReverseList(head);
	PrintList(reverseHead);
	return 0;
}

