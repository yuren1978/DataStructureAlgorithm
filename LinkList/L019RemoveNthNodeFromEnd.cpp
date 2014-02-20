

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */

class Solution {
public:
    ListNode *removeNthFromEnd(ListNode *head, int n) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        if(head==NULL) return NULL;
        
        ListNode* nFromBeginning=head;
        int i=0;
        while(i<n && nFromBeginning!=NULL){
            nFromBeginning=nFromBeginning->next;
            i++;
        }
              
        if(nFromBeginning==NULL) {
            if(i==n){
                ListNode* next=head->next;
                delete head;
                return next;
            }
            else{
                return head;
            }
        }
        
        ListNode* current=head;
        while(nFromBeginning->next!=NULL){
            nFromBeginning=nFromBeginning->next;
            current=current->next;
        }
        
        ListNode* nodeDelete=current->next;
        current->next=nodeDelete->next;
        delete nodeDelete;
        return head;
    }
};