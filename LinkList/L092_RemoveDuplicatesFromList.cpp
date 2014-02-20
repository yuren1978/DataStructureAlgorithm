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
    ListNode *deleteDuplicates(ListNode *head) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        if(head==NULL || head->next==NULL)
            return head;
        
        ListNode* dummy=new ListNode(-999);
        dummy->next=head;
        ListNode* prev=dummy;
        ListNode* current=head;
        ListNode* next=head->next;
        bool dulicateFound=false;
        while(current!=NULL){
            if(next!=NULL && current->val==next->val){
                //duplicate found
                dulicateFound=true;
                ListNode* deleteNode=current;
                current=current->next;
                next=current->next;
                prev->next=current;
                delete deleteNode;
            }
            else{
                if(dulicateFound){
                    ListNode* deleteNode=current;
                    current=current->next;
                    if(current!=NULL){
                         next=current->next;
                         prev->next=current;
                    }
                    else{
                        prev->next=NULL;   
                    }
                    delete deleteNode;
                }
                else{//move forward
                    prev=current;
                    current=next;
                    if(current!=NULL){
                        next=current->next;
                    }
                }
                dulicateFound=false;
            }
        }
        return dummy->next;
    }
};