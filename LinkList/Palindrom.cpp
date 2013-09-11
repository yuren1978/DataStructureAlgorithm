
#include <cstdio>
#include <cstdlib>
#include <stack>

using namespace std;
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


int main(int argc, char *argv[]) {
	int a[]={1,2,3,1};
	int size=sizeof(a)/sizeof(*a);
	ListNode* head=CreateListFromArray(a,size);
	bool isPalin=isPalindrome(head);
	if(isPalin){
		printf("\n Palindrome");
	}else {
		printf("\n Non-Palindrome");
	}
	
	
	return 0;	
}