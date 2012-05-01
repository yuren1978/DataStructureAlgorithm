#include <stdio.h>

typdef struct node {
	int value;
	struct node* next;
} Node;

int main(int argc, char *argv[]) {
	Node* head1=CreateFirstList();
	Node* head2=CreateSecondList();
	
}