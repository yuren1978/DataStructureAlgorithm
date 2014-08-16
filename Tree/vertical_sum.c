#define HD_OFFSET 16

void vertical_sum(Node *node, int hd, int sum[], int *min, int *max){

    /* We are offseting the index to access array correctly.
    Root will be at HD_OFFSET/2 index and all vertical lines on left will
    be at 0 to HD_OFFSET/2 and right side will be on HD_OFFSET/2 to HD_OFFSET */
    
    int index = hd + HD_OFFSET/2;

    if(!node) return;
    
    /* to keep track of min and max index filled in sum array */
    if(index > (*max)) (*max) = index;
    if(index < (*min)) (*min) = index;

    sum[index]+= node->value;
    /*If we are moving on the left side, 
    we will pass index as one less the current */
    vertical_sum(node->left, hd-1, sum, min, max);
    
    /*If we are moving on the right side, 
    we will pass index as one more the current */
    vertical_sum(node->right, hd+1, sum, min, max);
}

Node * create_node(int value){
    Node * temp =  (Node *)malloc(sizeof(Node));
    temp->value = value;
    temp->right= NULL;
    temp->left = NULL;
    return temp;
}
Node * addNode_1(Node *node, int value){
    if(node == NULL){
        return create_node(value);
    }
    else{
        if (node->value > value){
            node->left = addNode_1(node->left, value);
        }
        else{
            node->right = addNode_1(node->right, value);
        }
    }
    return node;
}

//Driver program
int main{
    int i;
    int sum[100] ={0, };
    int min = HD_OFFSET;
    int max = 0;

    Node *root = NULL;
    //Creating a binary tree
    root = addNode_1(root,6);
    root = addNode_1(root,3);
    root = addNode_1(root,2);
    root = addNode_1(root,1);
    root = addNode_1(root,7);
    root = addNode_1(root,5);
    root = addNode_1(root,9);

    vertical_sum(root, 0, sum, &min, &max);
    for(i=min;i<=max; i++){
        printf("\n %d", sum[i]);
    }

    return 0;
}
