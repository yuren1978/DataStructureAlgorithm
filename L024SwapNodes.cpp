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
	ListNode helper=new ListNode(0);
	helper->next=head;
	ListNode* n1=helper;
	ListNode* n2=head;
	while (n2!=NULL && n2->next!=NULL) {
		ListNode* temp=n2->next->next;
		n2->next->next=n1->next;
		n1->next=n2->next;
		n2->next=temp;
		
		n1=n2;
		n2=n2->next;
	}
	return helper->next;
}

int main(int argc, char *argv[]) {
	
}