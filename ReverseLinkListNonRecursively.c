typedef struct node
{
	int value;
	struct node* next;
} Node;

Node* MakeListFromArray(int* a, int start, int end){
	Node* head=0;
	for (int i=start; i<end; i++){
		Node* node=malloc(sizeof(Node));
		node->value=a[i];
		if(head==0){
			head=node;
		}
		else {
			node->next=head;
			head=node;
		}	
	}	
	return head;
}

void PrintList(Node* head){
	printf("\n" );
	Node* travelNode=head;
	while(travelNode!=0){
		printf("%d\t", travelNode->value);
		travelNode=travelNode->next;
	}
}

Node* ReverseList(Node* head){
	Node* firstNode=head;
	Node* secondNode=firstNode!=0?firstNode->next:0;
	Node* thirdNode=secondNode!=0?secondNode->next:0;
	head->next=0; 
	while(secondNode!=0){
		secondNode->next=firstNode;
		firstNode=secondNode;
		secondNode=thirdNode;
		thirdNode=secondNode!=0?secondNode->next:0;
	}
	return firstNode;
}

int main(int argc, char const *argv[])
{
	int a[]={0,1,2,3,4,5,6,7,8,9};
	int length=sizeof(a)/sizeof(*a);
	Node* head= MakeListFromArray(a, 0, length);
	PrintList(head);
	Node* reverseHead=ReverseList(head);
	PrintList(reverseHead);
	return 0;
}

