#include "stdio.h"
#include "stdlib.h"
#include "assert.h"


 bool between(int A[], int l, int r, int target){
        return target>=A[l] && target<=A[r];
    }

int FindPosInArray(int A[], int n, int target){
 		int l=0, r=n-1;
        while(l<r){
            int m=l+(r-l)/2;
            
            //printf("middle value %d\n", A[m] );
            if(target==A[m]) return m;
            
            if(A[l]<=A[m] && between(A, l, m, target)){
            	printf("go left\n");
                r=m-1;
            }
            else{
            	printf("go right\n");
                l=m+1;
            }

            printf("%d - %d\n", l, r );
        }
        
        return target==A[l]?l:-1;
}


int main(int argc, char const *argv[])
{

	int a[]={5,1,3};
	int length=sizeof(a)/sizeof(*a);	
	assert(0==FindPosInArray(a, length, 5));
	return 0;
}