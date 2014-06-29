//http://vcfvct.wordpress.com/2012/01/07/post-order-traversal-sequences-of-binary-search-trees/
//Determine whether an input array is a post-order traversal sequence of a binary tree or not. If it is, return true; otherwise return false. Assume all numbers in an input array are unique.


#include <fstream>
#include <iostream>
#include <deque>
#include <iomanip>
#include <sstream>
#include <string>
#include <cmath>
#include <cassert>

using namespace std;


bool IsArrayPostOrder(int array[], int start, int end){
}

int main() {
  
	int a[]={1,2,3,4,5,6,7,9,10};
	int sizeOfArray=sizeof(a)/sizeof(*a);
	BinaryTree* root=CreateTreeFromArray(a,0,sizeOfArray-1 );

  	cout << "Tree pretty print with level=1 and indentSpace=0\n\n";
//  	// Output to console
  	printPretty(root, 1, 0, cout);

	int array[]={1,3,2,5,7,6,4};
 	assert(true==IsArrayPostOrder(array, 0, 6)); 
	int array1[]={3,1,2,5,7,6,4};
	assert(false==IsArrayPostOrder(array1, 0, 6));
	int array2[]={1,4,3,2,6,10,9,7,5};
	assert(false==IsArrayPostOrder(array2, 0, 9));
  	return 0;
}