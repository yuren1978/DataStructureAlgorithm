

#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <cassert>

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

ListNode* findMiddle(ListNode* head){
	ListNode* fast=head->next;
	ListNode* slow=head;
	while(NULL!=fast){
		fast=fast->next;
		if(fast!=NULL){
			fast=fast->next;
			slow=slow->next;
		}
	}
	ListNode* middle=slow->next;
	slow->next=NULL;
	return middle;
}


ListNode* mergeLists(ListNode*  head1, ListNode* head2){
	if(NULL==head1) return head2;
	if(NULL==head2) return head1;
	ListNode* mergeHead=NULL;
	ListNode* temp=NULL;
	while(NULL!=head1 && NULL!=head2){
		if(head1->val < head2->val){
			if(temp==NULL) temp=head1;
			else{
				temp->next=head1;
				temp=head1;		
			}
			head1=head1->next;
		}
		else{
			if(temp==NULL) temp=head2;
			else{
				temp->next=head2;
				temp=head2;
			}
			head2=head2->next;
		}
		if(mergeHead==NULL)
			mergeHead=temp;
	}

	if(head1==NULL)
		temp->next=head2;
	else if(head2==NULL)
		temp->next=head1;

	return mergeHead;
}

ListNode* sortLinkList(ListNode* head){	
	if(NULL==head||NULL==head->next) return head;
	ListNode* middle=findMiddle(head);
	ListNode* firstPart=sortLinkList(head);
	ListNode* secondPart=sortLinkList(middle);
	ListNode* mergeList=mergeLists(firstPart, secondPart);
	return mergeList;
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
	int a[]={3,2,1,4,5};
	ListNode* head=CreateListFromArray(a,5);
	//ListNode* middle=findMiddle(head);
	//cout<<middle->val<<endl;
	//assert(3==middle->val);
	//PrintList(head);
	ListNode* newHead= sortLinkList(head);
	PrintList(newHead);
}
