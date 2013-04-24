#include <iostream>

using namespace std;


void printArray(int A[], int n){
     for (int i = 0; i < n; ++i)
    {
        cout<<A[i]<<" ";
    }
    cout<<endl;
}

int firstMissingPositive2(int A[], int n) {
    // Start typing your C/C++ solution below
    // DO NOT write int main() function
    //printArray(A, n);
    
     for(int i=0;i<n;i++){
        int target=A[i];
        while(target>0 && target<=n && target!=A[target-1]){           
            int newTarget = A[target-1];
            A[target-1] = target;
            target = newTarget;
        }
        printArray(A, n);
    }

   

    for(int i=0;i<n;i++){
        if(A[i]!=i+1)   return i+1;
    }
    return n+1;   
          
}



int main(int argc, char *argv[]) {
	int A[]={1,2,0};
	int missing=firstMissingPositive(A,3);
	cout<<missing<<endl;
}