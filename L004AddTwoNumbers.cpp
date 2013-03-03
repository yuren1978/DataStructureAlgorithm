//Input: (2 -> 4 -> 3) + (5 -> 6 -> 4)
//Output: 7 -> 0 -> 8

#include <iostream>

using namespace std;


 //Definition for singly-linked list.
 struct ListNode {
      int val;
      ListNode *next;
      ListNode(int x) : val(x), next(NULL) {}
  };
 

ListNode *addTwoNumbers(ListNode *l1, ListNode *l2) {
  // Start typing your C/C++ solution below
  // DO NOT write int main() function
   int carry=0;
   ListNode* p1=l1;
   ListNode* p2=l2;
	ListNode* head=NULL;
	ListNode* last=NULL;
	while (NULL!=p1 && NULL!=p2) {
		int v1=p1->val;
		int v2=p2->val;
		int sum=(v1+v2+carry)%10;
		carry=(v1+v2+carry)/10;
		ListNode* node=new ListNode(sum);
		if(head==NULL){
			head=node;
			last=node;
		}else {
			last->next=node;
			last=node;
		}
		p1=p1->next;
		p2=p2->next;
	}
	
	while (NULL!=p1) {
		int v1=p1->val;
		int sum=(v1+carry)%10;
		carry=(v1+carry)/10;
		ListNode* node=new ListNode(sum);
		last->next=node;
		last=node;
		p1=p1->next;
	}

	while (NULL!=p2) {
		int v2=p2->val;
		int sum=(v2+carry)%10;
		carry=(v2+carry)/10;
		ListNode* node=new ListNode(sum);
		last->next=node;
		last=node;
		p2=p2->next;
	}
	
	if(carry>0){
		ListNode* node=new ListNode(carry);
		last->next=node;
		last=node;
	}   
}

int main(int argc, char *argv[]) {
	
}