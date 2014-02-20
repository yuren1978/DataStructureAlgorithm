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
    ListNode *partition(ListNode *head, int x) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        if(head==NULL) return NULL;
        
        ListNode* largeHead=NULL;
        ListNode* largeTail=NULL;
        ListNode* smallHead=NULL;
        ListNode* smallTail=NULL;
        
        ListNode* current=head;
        while(current!=NULL){
            if(current->val<x){
                if(smallHead==NULL){
                    smallHead=current;
                    smallTail=current;
                }
                else{
                    smallTail->next=current;
                    smallTail=smallTail->next;
                }
            }
            else{
                if(largeHead==NULL){
                    largeHead=current;
                    largeTail=current;
                }
                else{
                    largeTail->next=current;
                    largeTail=largeTail->next;
                }
            }
            current=current->next;
        }
        
        if(smallHead!=NULL){
            smallTail->next=largeHead;
            if(largeTail!=NULL){
                largeTail->next=NULL;
            }
            return smallHead;
        }
        else{
            return largeHead;
        }
        
       
    }
};