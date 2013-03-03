#include <iostream>
#include <vector>

using namespace std;

int maxSums(int* diffArray, int size)
{
	int sum=0;
	for (int i=0; i<size; ++i) {
		if(diffArray[i]>0){
			sum+=diffArray[i];
		}
	}
	return sum;
}

int maxProfit(vector<int> &prices) {
     	// Start typing your C/C++ solution below
     	// DO NOT write int main() function
     	int maxProfit=0;
		int size=prices.size();
		if(size<=1)
			return 0;  
		int* diff=new int[size-1];
		for (int i=1; i<size; i++) {
			diff[i-1]=prices[i]-prices[i-1];
		}
		maxProfit=maxSums(diff, size-1);
		delete[] diff;	 
		return maxProfit;
}




int main(int argc, char *argv[]) {
	
}