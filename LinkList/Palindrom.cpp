
#include <cstdio>
#include <cstdlib>
#include <stack>
//http://www.geeksforgeeks.org/archives/1072




struct ListNode{
	int val;
	struct ListNode* next;
	ListNode(int x) : val(x), next(NULL) {}
} ;

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
	ListNode* orginalHead=head;
	stack<int> s;
	while(head!=NULL){
		s.push(head->val);
		head=head->next;
	}
	while(orginalHead!=NULL){
		int top=s.top();
		if(orginalHead->val!=top){
			return false;
		}
		s.pop();
		orginalHead=orginalHead->next;
	}
	return true;
}


int main(int argc, char *argv[]) {
	int a[]={1,2,3,4,3,2};
	ListNode* head=CreateListFromArray(a,7);
	bool isPalin=isPalindrome(head);
	if(isPalin){
		printf("\n Palindrome");
	}else {
		printf("\n Non-Palindrome");
	}
	
	
	return 0;	
}