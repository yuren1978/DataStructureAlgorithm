

typedef struct node
{
	int value;
	struct node* left;
	struct node* right;  
} Node;

Node* ConvertArrayToTree(int* a, int start, int end)
{
	if(start<=end){
		int middle=(start+end)/2;
		Node node=malloc(sizeof(Node));
		node->value=a[middle];
		node->left=ConvertArrayToTree(a, start, middle-1);
		node->right=ConvertArrayToTree(a, middle+1,end);
		return node;			
	}
	else{
		return 0;
	}
}

void InOrderPrint(Node* root){
	if(root!=0){
		InOrderPrint(root->left);
		printf("%d\t", root->value);
		InOrderPrint(root->right);
	}
}

void TreeToCircularDoubleLinkList(Node* node, Node* & head, Node* & prev){
	if(node!=0){
		TreeToCircularDoubleLinkList(node->left, head, prev);
		if(node->left!=0){
			prev=node->left;
		}
		else{//only be set once.
			head=node;
		}
		if(prev!=0){
			prev->right=node;
		}
		node->left=prev;
		Node* right=node->right;
		head->right=node;
		prev=node;
		TreeToCircularDoubleLinkList(right, head, prev);		
	}
}


int main(int argc, char const *argv[])
{
	int a[]={1,2,3,4,5,6,7,8,9,10};
	int length=sizeof(a)/sizeof(*a);
	Node root=ConvertArrayToTree(a,0, length-1);
	InOrderPrint(root);
	printf("end of printing\n");
	Node* head=0;
	Node* prev=0;
	TreeToCircularDoubleLinkList(root,head, prev);
	PrintDoubleLinkList(head);
	return 0;
}