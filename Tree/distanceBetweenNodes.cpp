
#include <iostream>
#include <cassert>

using namespace std;

struct Node
{
    struct Node *left, *right;
    int key;
};

Node* newNode(int key)
{
    Node *temp = new Node;
    temp->key = key;
    temp->left = temp->right = NULL;
    return temp;
}

int findDistance(Node *root, int n1, int n2){
	
	return 0;
}



int main()
{
    // Let us create binary tree given in the above example
    Node * root = newNode(1);
    root->left = newNode(2);
    root->right = newNode(3);
    root->left->left = newNode(4);
    root->left->right = newNode(5);
    root->right->left = newNode(6);
    root->right->right = newNode(7);
    root->right->left->right = newNode(8);

    //assert the distance between the nodes.
    assert(2==findDistance(root, 4, 5));
    assert(4==findDistance(root, 4, 6));
    assert(3==findDistance(root, 3, 4));
    assert(1==findDistance(root, 2, 4));
    assert(5==findDistance(root, 8, 5));
    return 0;
}
