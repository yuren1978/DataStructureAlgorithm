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
	ListNode* prev=new ListNode(0);
	prev->next=head;
	ListNode* helper=prev;
	ListNode* current=head;
	while (current!=NULL && current->next!=NULL) {
		
		ListNode* temp=current->next->next;
		current->next->next=prev->next;
		prev->next=current->next;
		current->next=temp;
		
		prev=current;
		current=current->next;
	}
	return helper->next;
}

int main(int argc, char *argv[]) {
	
}