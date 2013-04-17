#include <iostream>

using namespace std;

//The key idea is to put every element in A such that A[i]=i

// void ExchangeNumber(int A[], int poistion1, int position2){
// 	int temp=A[poistion1];
// 	A[poistion1]=A[position2];
// 	A[poistion2]=temp;
// }

void printArray(int A[], int n){
     for (int i = 0; i < n; ++i)
    {
        cout<<A[i]<<" ";
    }
    cout<<endl;
}


int firstMissingPositive(int A[], int n) {
    // Start typing your C/C++ solution below
    // DO NOT write int main() function
    printArray(A, n);
    
     for(int i=0;i<n;i++){
        while(A[i]!=i+1){
           if(A[i] <= 0 || A[i] > n || A[i] == A[A[i]-1]) break;
            int temp = A[i];
            A[i] = A[temp-1];
            A[temp-1] = temp;
        }
        printArray(A, n);
    }

   

    for(int i=0;i<n;i++){
        if(A[i]!=i+1)   return i+1;
    }
    return n+1;   
	      
}

int main(int argc, char *argv[]) {
	int A[]={3,4.,-1,1};
	int missing=firstMissingPositive(A,4);
	cout<<missing<<endl;
}