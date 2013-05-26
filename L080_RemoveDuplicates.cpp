#include <iostream>
#include <map>

using namespace std;


int removeDuplicates(int A[], int n) {
    // Start typing your C/C++ solution below
    // DO NOT write int main() function
    int currentCount=n;
    map<int, int> intCount;

    for (int i = 0; i < n; ){
    	int number=A[i];
    	if(intCount.find(A[i])==intCount.end()){
    		intCount[A[i]]=1;
    		++i;	
    		//cout<<"nothing"<<i<<endl;
    	}
    	else if(intCount[A[i]]==1){
    		intCount[A[i]]=2;
    		++i;
    		//cout<<"find one"<< i<<endl;
    	}
    	else{//remove the current element, and move other element forward.
	    		for(int j=i; j<n-1; j++){
    			A[j]=A[j+1];
    		}	    			
			n--;
    	}
    }
    return  n; 
}

int main(){
	int A[]={1,1,1};
	removeDuplicates(A, 3);
	return 0;
}