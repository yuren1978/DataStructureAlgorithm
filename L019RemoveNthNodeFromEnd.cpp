#include <iostream>

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */

ListNode *removeNthFromEnd(ListNode *head, int n) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
		if(0==n)
			return head;

		ListNode* originalHead=head;
        ListNode* nodeFromBeginning=head;
        while(NULL!=nodeFromBeginning && n>0){
        	nodeFromBeginning=nodeFromBeginning->next;
        	--n;
        }

        if(NULL==nodeFromBeginning){
        	if(n>0){
        		return head;
        	}
        	else{
        		head=head->next;
        		delete originalHead;
        		return head;
        	}
        }

        while(NULL!=nodeFromBeginning->next){
        	nodeFromBeginning=nodeFromBeginning->next;
        	head=head->next;
        }

        ListNode* nodeBeDeleted=head->next;
        head->next=nodeBeDeleted->next;
        delete nodeBeDeleted;
        return originalHead;
 }