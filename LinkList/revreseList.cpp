#include <iostream>

using namespace std;

struct Node{
	int value;
	Node* next;
	Node(int v):value(v),next(NULL){};
};

Node* createList(){
	Node* head=new Node(1);
	head->next=new Node(2);
	head->next->next=new Node(3);
	return head;
}

Node* reverseRcursively(Node* head){
	if(NULL==head||NULL==head->next)
		return head;

	Node* next=head->next;

	
	Node* reverseHead=reverseRcursively(next);
	
	next->next=head;
	head->next=NULL;

	return reverseHead;
}

Node* reverse(Node* head){
	if(NULL==head || NULL==head->next)
		return head;

	Node* prev=NULL;
	Node* current=head;

	while(current){
		Node* next=current->next;
		current->next=prev;
		prev=current;
		current=next;
	}
	return prev;
}

Node * mergeTwoLists(Node *l1, Node *l2) {
        if(NULL==l1) return l2;
        if(NULL==l2) return l1;
        
        Node* dummy=new Node(0);
        Node* tail=dummy;
        while(l1!=NULL && l2!=NULL){
            if(l1->value<=l2->value){
                tail->next=l1;
                tail=l1;
                l1++;
            }
            else{
            	cout<<"come here"<<endl;
                tail->next=l2;
                tail=l2;
                l2++;
            }
        }
        cout<<"come here"<<endl;
        if(l1)
            tail->next=l1;
        else
            tail->next=l2;
            
        return dummy->next;        
    }

void printList(Node* head){
	Node* current=head;
	while(current){
		cout<<current->value;
		current=current->next;
	}
	cout<<endl;
}



int main(int argc, char const *argv[])
{
	//Node* head=createList();
	//printList(head);
	//Node* reverseHead=reverseRcursively(head);
	//printList(reverseHead);	

	Node* l1=new Node(1);
	Node* l2=new Node(2);
	Node* m=mergeTwoLists(l1,l2);
	return 0;
}

