//http://zhedahht.blog.163.com/blog/static/2541117420116135376632/
//在数组中，数字减去它右边的数字得到一个数对之差。求所有数对之差的最大值。例如在数组{2, 4, 1, 16, 7, 5, 11, 9}中，数对之差的最大值是11，是16减去5的结果。

#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <limits.h>

int maxDiff3(int* number, unsigned int length){
	int compare=number[length-1];
	int max=0;
	for (int i = length-1; i>=0; --i){
		if(number[i]>compare){
			if(number[i]-compare>max)
				max=number[i]-compare;
		}
		else{
			compare=number[i];
		}
	}
	return max;
}

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

int MaxDiffSolutionDivideAndConquereCore(int* start, int* end, int* min, int* max){
	if(start==end){//point same
		*max=*min=	*start;
		return INT_MIN;
	}
	
	int* middle=start+(end-start)/2;
	int leftMin, leftMax;
	int leftMaxDiff=MaxDiffSolutionDivideAndConquereCore(start, middle, &leftMin, &leftMax);
	int rightMin, rightMax;
	int rightMaxDiff=MaxDiffSolutionDivideAndConquereCore(middle+1, end, &rightMin, &rightMax);
	
	int crossDiff=leftMax-rightMin;
	
	*max=rightMax>leftMax? rightMax:leftMax;
	*min=leftMin<rightMin ? leftMin:rightMin;
	
	int maxDiff=leftMaxDiff>rightMaxDiff?leftMaxDiff:rightMaxDiff;
	maxDiff=maxDiff>crossDiff? maxDiff: crossDiff;
		
	return maxDiff;
}


int MaxDiffSolutionDivdeAndConqure(int* number, unsigned int length){
	if(number==NULL||length<2)
		return 0;
		
	int min, max;
	return MaxDiffSolutionDivideAndConquereCore(number,number+length-1,&min, &max);
}


int main(int argc, char *argv[]) {
	int a[]={2, 4, 1, 16, 7, 5, 11, 9};
	int length=sizeof(a)/sizeof(*a);

	assert(11==MaxDiffSolutionDivdeAndConqure(a,length));
	assert(11==MaxDiffDynamic(a,length));
	assert(11==maxDiff3(a,length));

}