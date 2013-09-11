/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */

#include <iostream>
#include <vector>

 using namespace std;

struct ListNode {
	int val;
	ListNode *next;
 	ListNode(int x) : val(x), next(NULL) {}
 };

ListNode* mergeTwoList(ListNode* head1, ListNode* head2){
	if(NULL==head1) return head2;
	if(NULL==head2) return head1;
	ListNode* head=NULL;
	ListNode* tail=NULL;
	while(NULL!=head1 && NULL!=head2){
		if(head1->val<head2->val){
			if(NULL==head){
				head=head1;
				tail=head1;
			}
			else{
				tail->next=head1;
				tail=tail->next;
			}		
			head1=head1->next;	
		}
		else{
			if(NULL==head){
				head=head2;
				tail=head2;
			}
			else{
				tail->next=head2;
				tail=tail->next;
			}	
			head2=head2->next;
		}
	}
	if(NULL==head1){
		tail->next=head2;
	}
	else{
		tail->next=head1;
	}
	return head;
} 

void mergeKListsRecursive(vector<ListNode *> &lists, int start, int end, ListNode** head){
	if(start==end){
		*head=lists[start];
		return;
	}
	ListNode* head1=NULL;
	ListNode* head2=NULL;
	int middle=(start+end)/2;
	mergeKListsRecursive(lists, start, middle, &head1);
	mergeKListsRecursive(lists, middle+1, end, &head2);
	*head=mergeTwoList(head1, head2);
}


 ListNode *mergeKLists(vector<ListNode *> &lists) {
     // Start typing your C/C++ solution below
     // DO NOT write int main() function
 	int size=lists.size();
  	ListNode* head=NULL;
  	mergeKListsRecursive(lists,0, size-1, &head); 
  	return head;
}

int main(int argc, char *argv[]){
	return 0;
}