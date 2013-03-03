#include <iostream>

using namespace std;

struct ListNode {
     int val;
     ListNode *next;
     ListNode(int x) : val(x), next(NULL) {}
};

ListNode *swapPairs(ListNode *head) {
    // Start typing your C/C++ solution below
    // DO NOT write int main() function
	if(NULL==head || NULL==head->next){
		return head;
	}        
	ListNode* oddHead=head; ListNode* oddTail=head;
	ListNode* evenHead=head->next; ListNode* evenTail=head->next;
	while (NULL!=evenTail) {
		ListNode* oddNext=evenTail->next;
		ListNode* evenNext=oddNext!=NULL ? oddNext->next:NULL;
		
		oddTail->next=oddNext;
		evenTail->next=evenNext;
		
		oddTail=oddNext;
		evenTail=evenNext;
	}
	
	//now we need connect them back
	ListNode* returnHead=evenHead;
	
	while (NULL!=evenHead) {
		ListNode* oddNext=oddHead->next;
		ListNode* evenNext=evenHead->next;
		evenHead->next=oddHead;
		oddHead->next=NULL!=evenNext?evenNext:oddNext;
		
		evenHead=evenNext;
		oddHead=oddNext;
	}	
	return returnHead;
}

int main(int argc, char *argv[]) {
	
}