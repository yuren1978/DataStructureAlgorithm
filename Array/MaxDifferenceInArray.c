//http://zhedahht.blog.163.com/blog/static/2541117420116135376632/
//在数组中，数字减去它右边的数字得到一个数对之差。求所有数对之差的最大值。例如在数组{2, 4, 1, 16, 7, 5, 11, 9}中，数对之差的最大值是11，是16减去5的结果。
//same with the stock  problem as leetcode.

#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <limits.h>


int MaxDiffDynamic(int* number, unsigned int length){
	if(number==NULL||length<2)
		return 0;
	
	int maxDiff=number[0]-number[1];
	int maxNumber=number[0];
	for (int i=2; i<length; i++) {//the last number will be length-1
		if(number[i-1]>maxNumber){
			maxNumber=number[i-1];
		}
		int currentMaxDiff=maxNumber-number[i];
		if(currentMaxDiff>maxDiff){
			maxDiff=currentMaxDiff;
		}
	}
	return maxDiff;		
}





int main(int argc, char *argv[]) {
	int a[]={2, 4, 1, 16, 7, 5, 11, 9};
	int length=sizeof(a)/sizeof(*a);
	int maxDiff1=MaxDiffDynamic(a,length);
	assert(11==maxDiff);
	assert(11==maxDiff1);
}