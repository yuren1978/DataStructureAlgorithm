#include <iostream>

using namespace std;

//http://www.mitbbs.com/article_t1/JobHunting/32233991_0_1.html

void ExchangeNumber(int A[], int poistion1, int position2){
	int temp=A[poistion1];
	A[poistion1]=A[position2];
	A[poistion2]=temp;
}


int MoveNegativeNumerToFront(int A[], int n){
	int numberOfNegative=0;
	for (int i=0; i<n; ++i) {
		if(A[i]<=0){
			ExchangeNumber(A, i, numberOfNegative++);
		}
	}
	return numberOfNegative;
}

int MarkNumberSeenToNegative(int A[], int n){
	for (int i=0; i<n; ++i) {
		int numberToSee=A[i];
		if(numberToSee<0){
			numberToSee=-numberToSee;
		} 	
		int indexToSet=numberToSee-1;
		if(A[indexToSet]>0 && indexToSet<n)
			A[indexToSet]=-A[indexToSet];	
	}
	for (int i=0; i<n; ++i) {
			if(A[i]>0){
				return i+1;
			}
		}
	return n+1;  
}


int firstMissingPositive(int A[], int n) {
    // Start typing your C/C++ solution below
    // DO NOT write int main() function
   int numberOfNegative= MoveNegativeNumerToFront(A, n);
	return MarkNumberSeenToNegative(A+numberOfNegative, n-numberOfNegative );    
	      
}

int main(int argc, char *argv[]) {
	
}