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
	Node* prev=(Node*) malloc(sizeof(Node));
	prev->value=0;
	prev->next=head;
	Node* current=prev->next;
	while(current->next!=NULL){
		Node* temp=current->next;
		current->next=temp->next;
		temp->next=prev->next;
		prev->next=temp;
	}
	return prev->next;
}

int main(int argc, char const *argv[])
{
	int a[]={0,1};
	int length=sizeof(a)/sizeof(*a);
	Node* head= MakeListFromArray(a, 0, length);
	//printf("%d\n", head->next->value);
	PrintList(head);
	Node* reverseHead=ReverseList(head);
	PrintList(reverseHead);
	return 0;
}

