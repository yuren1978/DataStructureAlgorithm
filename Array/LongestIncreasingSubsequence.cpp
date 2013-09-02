//http://www.youtube.com/watch?v=U-xOVWlcgmM
//http://www.geeksforgeeks.org/archives/12832
//http://stackoverflow.com/questions/2631726/how-to-determine-the-longest-increasing-subsequence-using-dynamic-programming

//The longest Increasing Subsequence (LIS) problem is to find the length of the longest subsequence of a given sequence 
//such that all elements of the subsequence are sorted in increasing order. 
//For example, length of LIS for { 10, 22, 9, 33, 21, 50, 41, 60, 80 } is 6 and LIS is {10, 22, 33, 50, 60, 80}.

#include <iostream>
#include <cstdio>
#include <vector>
#include <climits>

using namespace std;

void printVector(const vector<int>& v){
	for (int i = 0; i < v.size(); ++i){
		cout<<v[i]<<" ";
	}
	cout<<endl;
}

vector<int> getLIS(int A[], int n){
	vector<int> dp(n, 1);
	vector<int> prev(n, -1);
	for (int i = 1; i < n; ++i){
		for(int j=i-1; j>=0; j--){
			if(dp[j]+1>dp[i] && A[j]<A[i]){
				dp[i]=dp[j]+1;
				prev[i]=j;
			}
		}
	}

	int maxEndIndex=-1;
	int maxLength=INT_MIN;
	for (int i = 0; i < n; ++i){
		if(dp[i]>maxLength){
			maxLength=dp[i];
			maxEndIndex=i;
		}
	}

	vector<int> lcs;
	vector<int> lisIndexes;
	
	int prevIndex=maxEndIndex;
	do{
		lisIndexes.push_back(prevIndex);
		prevIndex=prev[prevIndex];
	}while(prevIndex!=-1);

	int size=lisIndexes.size();
	for (int i = size-1; i >=0; --i){
		lcs.push_back(A[lisIndexes[i]]);
	}
	return lcs;
}


int main(int argc, char *argv[]) {
	int arr[] = { 10, 22, 9, 33, 21, 50, 41, 60, 80 };
  	int n = sizeof(arr)/sizeof(arr[0]);
  	vector<int> lcs=getLIS(arr, n); 
  	printVector(lcs);
  	getchar();
  	return 0;
}