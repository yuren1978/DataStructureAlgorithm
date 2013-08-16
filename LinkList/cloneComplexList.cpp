//http://zhedahht.blog.163.com/blog/static/254111742010819104710337/
//http://www.mitbbs.com/article_t/JobHunting/31342084.html
//http://www.geeksforgeeks.org/a-linked-list-with-next-and-arbit-pointer/
//2. 复制linked list。 已知每个节点有两个pointer，一个指向后一个节点，另一个指向
//   其他任意一节点。 O(n)时间内，无附加内存，复制该linked list。（存储不连续）

#include <iostream>
#include <cstdio>
#include <map>

using namespace std;


struct ListNode{
	int val;
	struct ListNode* next;
	struct ListNode* arbit;
	ListNode(int x) : val(x), next(NULL), arbit(NULL) {}
} ;



void push(struct ListNode** head_ref, int new_data)
{
    /* allocate node */
    struct ListNode* new_node = new ListNode(new_data);
    /* link the old list off the new node */
    new_node->next = (*head_ref);
    /* move the head to point to the new node */
    (*head_ref)    = new_node;
}

void printList(struct ListNode *node)
{
    while(node != NULL)
    {
       if(node->next==NULL)
        {
             printf("next and arbitary of %d is NULL and %d \n",node->val ,node->arbit->val);
        }
        else
        printf("next and arbitary of %d is %d and %d \n",node->val ,node->next->val,node->arbit->val);
        node = node->next;
    }
    printf("\n");
}

struct ListNode* copyList(struct ListNode* original){
	map<ListNode*, ListNode*> listCopy;
	ListNode* copyHead=NULL;
	ListNode* temp=original;
	while(NULL!=temp){
		ListNode* newNode=new ListNode(temp->val);
		listCopy[temp]=newNode;
		temp=temp->next;
	}

	temp=original; //reset to head;

	while(NULL!=temp){
		ListNode* copyNode=listCopy[temp];
		copyNode->next=listCopy[temp->next];
		copyNode->arbit=listCopy[temp->arbit];
		if(NULL==copyHead){
			copyHead=copyNode;
		}
		temp=temp->next;
	}
	return copyHead;
}

int main()
{
    struct ListNode* original=NULL, *copy=NULL;
    push(&original, 5);
    push(&original, 4);
    push(&original, 3);
    push(&original, 2);
    push(&original, 1);
    original->arbit = original->next->next;
    original->next->arbit = original;
    original->next->next->arbit = original->next->next->next->next;
    original->next->next->next->arbit = original->next->next;
    original->next->next->next->next->arbit = original->next;
    printList(original);
    copy = copyList(original);
    printf("copy of the linklist with next and arbit pointer\n");
    printList(copy);
    return 0;
}