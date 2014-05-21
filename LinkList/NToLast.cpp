/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */

ListNode *removeNthFromEnd(ListNode *head, int n) {
	
	if(NULL==head)    return NULL;
	
	ListNode* fast=head;
	ListNode* slow=head;
	
	while(n-->0){
		fast=fast->next;
	}

	if(NULL==fast){
		return slow->next;
	}

	while(NULL!=fast->next){
		slow=slow=>next;
		fast=fast->next;
	}

	ListNode* slowNext=slow->next;
	slow->next=slowNext->next;
	return head;

}