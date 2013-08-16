
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
	while(p!=NULL) {
		printf("%d \t", p->val);
		p=p->next;
	} 
	printf("\n");
}

ListNode* getMiddleList(ListNode* startNode){
	if(startNode==NULL||startNode->next==NULL)
		return NULL;	

	ListNode* prevSlow=new ListNode(0);
	prevSlow->next=startNode;
	ListNode* fast=startNode;

	while(fast!=NULL && fast->next!=NULL){
		fast=fast->next->next;
		prevSlow=prevSlow->next;
	}

	ListNode* middle=prevSlow->next;
	prevSlow->next=NULL;

	//cout<<startNode->val<<endl;
	return middle;
};


ListNode* merge(ListNode* firstHalf, ListNode* secondHalf){
	if(NULL==firstHalf) return secondHalf;
	if(NULL==secondHalf) return firstHalf;
	ListNode* prev=new ListNode(0);
	ListNode* tail=prev;


	while(NULL!=firstHalf && NULL !=secondHalf){
		if(firstHalf->val < secondHalf->val ){
			if(prev->next==NULL) prev->next=firstHalf;

			tail->next=firstHalf;
			tail=firstHalf;
			firstHalf=firstHalf->next;			
			
		}
		else{
			if(prev->next==NULL) prev->next=secondHalf;

			tail->next=secondHalf;
			tail=secondHalf;
			secondHalf=secondHalf->next;
			
		}
	}

	if(NULL==firstHalf){
		tail->next=secondHalf;
	}
	else{
		tail->next=firstHalf;
	}

	return prev->next;
}


ListNode* sortLinkList(ListNode* startNode){
	if(NULL==startNode || NULL==startNode->next){
		return startNode;
	}

	ListNode* middle=getMiddleList(startNode);
	//cout<<"middle value "<< middle->val<<endl;
	//PrintList(startNode);


	ListNode* firstHalf=sortLinkList(startNode);
	ListNode* secondHalf=sortLinkList(middle);



	ListNode* mergeList=merge(firstHalf, secondHalf);

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
	int a[]={2,1, 3}; //int b[]={4,2};
	ListNode* head=CreateListFromArray(a,sizeof(a)/sizeof(*a));
	//ListNode* headB=CreateListFromArray(b,sizeof(b)/sizeof(*b));
	//ListNode* mergeHead=merge(headA, headB);
	//PrintList(mergeHead);

	PrintList(head);
	ListNode* newHead= sortLinkList(head);
	PrintList(newHead);
}
