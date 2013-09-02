//http://www.mitbbs.com/article_t1/JobHunting/32156867_0_1.html
//1.求一个数字数组里的最大连续数字的个数。
//3, 4, 4, 4, 2, 2, 3, 4  =>  return 3

#include <cstdio>
#include <cassert>
#include <algorithm>
#include <iostream>
#include <cmath>

using namespace std;

int GetMaximumCount(int A[], int length){
	if(1==length) return 1; 
	int maxCount=0;
	int l=0;
	int val=A[0];
	for (int i = 1; i < length; ++i){
		if(val!=A[i]){
			cout<<"l is "<<l<<"i is "<<i<<endl;
			maxCount=max(maxCount, i-l);
			l=i;
			val=A[i];
		}
	}
	return maxCount;
}

int main(int argc, char *argv[]) {
	int a[]={3, 4, 4, 4, 2, 2, 3, 4};
	int length=sizeof(a)/sizeof(*a);
	int maxCount=GetMaximumCount(a, length);
	printf("count is %d ", maxCount);
	//assert(3==GetMaximumCount(a,length));
	return 0;
}

