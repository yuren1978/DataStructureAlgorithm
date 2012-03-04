typedef	struct treeNode
{
	int value;
	struct treeNode* leftChild;
	struct treeNode* rightChild;
} TreeNode;


TreeNode* MakeTreeFromArray(int* a, int start, int end){
	if(start<=end)	{
		int middle=(start+end)/2;
		TreeNode* treeNode=malloc(sizeof(TreeNode));
		treeNode->value=a[middle];
		treeNode->leftChild=MakeTreeFromArray(a, start, middle-1);
		treeNode->rightChild=MakeTreeFromArray(a, middle+1, end);
		return treeNode;
	}
	else {
		return 0;
	}
}

void InOrderTravel(TreeNode* root){
	if(root!=0){
		InOrderTravel(root->leftChild);
		printf("%d\t", root->value);
		InOrderTravel(root->rightChild);		
	}
}

TreeNode* LowestCommonAncestor(const TreeNode* root, int leftValue, int rightValue)
{
	if(root==0)
		return 0;
	if(root->value==leftValue||root->value==rightValue)		return root; 
	TreeNode* leftLcs=LowestCommonAncestor(root->leftChild, leftValue, rightValue);
	TreeNode* rightLcs=LowestCommonAncestor(root->rightChild, leftValue, rightValue);	if(leftLcs!=0 && rightLcs!=0)
		return root;
	else {
		if(leftLcs!=0)
			return leftLcs;
		else 
			return rightLcs;
	}	
			
}

int main(int argc, char const *argv[])
{
	/* code */
	int a[]={1,2,3,4,5,6,7,8,9,10};
	int length=sizeof(a)/sizeof(*a);
	printf("The lenght of the array is %d \n", length);
	TreeNode* root=MakeTreeFromArray(a,0,length-1);
	printf("print tree with root value %d\n", root->value);
	InOrderTravel(root);
	
	TreeNode* lcs_1_9=LowestCommonAncestor(root, 1,9);
	printf("lcs of 1 and 9 is %d\n", lcs_1_9->value);
	
	return 0;
}