#include <iostream>

using namespace std;

int maxOfThree(int a, int b, int c){
    return max(max(a,b), c);
}

int minOfThree(int a, int b, int c){
    return min(min(a,b), c);
}

int maxProduct(int A[], int n) {
        int maxProduct=A[0];
        int preMaxSoFar=A[0];
        int preMinSoFar=A[0];
        for(int i=1; i<n; i++){
        	
            int maxSoFar=maxOfThree(preMaxSoFar*A[i], preMinSoFar*A[i], A[i]);
            int minSoFar=minOfThree(preMaxSoFar*A[i], preMinSoFar*A[i], A[i]);
            
            maxProduct=max(maxSoFar, maxProduct);

            preMaxSoFar=maxSoFar;
            preMinSoFar=minSoFar;
            
        }
        return maxProduct;
    }

int main(int argc, char const *argv[])
{
	/* code */
	int A[]={-4,-3,-2};
	int maxP=maxProduct(A,3);
	cout<<maxP<<endl;
	return 0;
}