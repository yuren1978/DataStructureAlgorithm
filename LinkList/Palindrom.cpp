
#include <cstdio>
#include <cstdlib>
#include <stack>
#include <iostream>


using namespace std;
//http://www.geeksforgeeks.org/archives/1072
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


 ListNode* getMiddleOfList(ListNode* head){
        ListNode* prev=NULL;
        ListNode* fast=head;
        ListNode* slow=head;
        while(NULL!=fast){
            fast=fast->next;
            if(NULL==fast){
                break;
            }
            prev=slow;
            slow=slow->next;
            fast=fast->next;
        }
        prev->next=NULL;
        return slow;
    }

    ListNode* reverseList(ListNode* head){
        ListNode* prev=new ListNode(0);
        prev->next=head;
        ListNode* current=head;
        while(current->next!=NULL){
            ListNode* temp=current->next;
            current->next=temp->next;
            temp->next=prev->next;
            prev->next=temp;
        }
        return prev->next;
    }

    void mergeList(ListNode* head, ListNode* reverseHead){
    	ListNode* nextFirst;
    	ListNode* nextSecond;
        ListNode* first=head;
        ListNode* second=reverseHead;
        ListNode* last;
        
        while(NULL!=first && NULL!=second){
            nextFirst=first->next;
            nextSecond=second->next;
            last=first;
            first->next=second;

            second->next=nextFirst;
            first=nextFirst;
            second=nextSecond;
        }

        if(first!=NULL){
        	last->next=second;
        }
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

bool isPalindrome(ListNode* head){
	stack<int> s;
	ListNode* originalHead=head;
	while(NULL!=head){
		s.push(head->val);
		head=head->next;
	}
	while(NULL!=originalHead){
		int top=s.top();
		s.pop();
		if(top!=originalHead->val)
			return false;
		originalHead=originalHead->next;
	}
	return true;
}

 void reorderList(ListNode *head) {
        if(NULL==head || NULL==head->next || NULL==head->next->next)
            return;
        // IMPORTANT: Please reset any member data you declared, as
        // the same Solution instance will be reused for each test case.
        ListNode* middleOfList=getMiddleOfList(head);
        ListNode* reveseHead=reverseList(middleOfList);
        

        PrintList(head);
        PrintList(reveseHead);

        mergeList(head, reveseHead);
        
    }


int main(int argc, char *argv[]) {
	int a[]={1,2,3};
	int size=sizeof(a)/sizeof(*a);
	ListNode* head=CreateListFromArray(a,size);
	reorderList(head);
	PrintList(head);
	
	return 0;	
}