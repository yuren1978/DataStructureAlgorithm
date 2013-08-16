

#include <cstdio>
#include <cstdlib>
#include <iostream>

using namespace std;

struct ListNode{
	int val;
	struct ListNode* next;
	ListNode(int x) : val(x), next(NULL) {}
} ;


void PrintList(ListNode* startNode){
	cout<<"list is"<<endl;
	ListNode* p=startNode;
	do {
		printf("%d \t", p->val);
		p=p->next;
	} while (p!=NULL) ;
	printf("\n");
}


void mergeList(ListNode* & head, ListNode* insert){
	//cout<<insert->val<<endl;
	//cout<<"head value" << head->val <<endl;
	if(insert->val<head->val){
		insert->next=head;
		head=insert;	
		return;	
	}
	ListNode* h1=head;
	while(h1->next!=NULL && h1->next->val < insert->val){
		h1=h1->next;
	}	
	ListNode* temp=h1->next;
	h1->next=insert;
	insert->next=temp;
	return;
}

ListNode* sortLinkList(ListNode* head){	
	if(NULL==head) return NULL;
	ListNode* newHead=head;
	ListNode* current=head->next;
	newHead->next=NULL;
	while(current!=NULL){		
		ListNode* temp=current->next;
		mergeList(newHead, current);		
		current=temp;
	}
	return newHead;
}

ListNode* CreateListFromArray(int* a , int length)
{
	ListNode* head=0;
	for (int index=0; index<length;index++) {
		ListNode* newNode=new ListNode(a[index]);
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


int main(){
	int a[]={1,2,5,3,4,8,9};
	ListNode* head=CreateListFromArray(a,7);	
	//PrintList(head);
	ListNode* newHead= sortLinkList(head);
	PrintList(newHead);
}
