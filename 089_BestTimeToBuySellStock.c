//http://www.leetcode.com/2010/11/best-time-to-buy-and-sell-stock.html
// was given an interview question on this, but they had a following question: if you can keep buying and selling, how to maximize the profit? for example, if it is 6,1,3,2,4,7, we can buy for 1 and sell for 3, and we can buy for 2, and sell for 4,then buy on 4, sell for 7. total maxval =3-1+4-2+7-4 = 7. They would like to have some O(n) solutions
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

int BestTimeBuySendStock(int* array, int length, int* start, int* end)
{
	if(array==NULL||length==1){
		start=0;
		end=0;
		return 0;
	}
	int startIndex=0;
	int endIndex=1;
	int minPrice=array[startIndex];
	int maxProfit=array[endIndex]-array[startIndex];
	for (int i=2; i<length; i++) {
		if(array[i-1] < minPrice){//update min price if needed
			minPrice=array[i-1];
			startIndex=i-1;	
		}
		
		if((array[i]-minPrice)>maxProfit){
			maxProfit=array[i]-minPrice;
			*start=startIndex;
			*end=i;
		}
	}
	return maxProfit;	
}

int main(int argc, char *argv[]) {
	int a[]={2, 4, 1, 16, 7, 5, 11, 9};
	int length=sizeof(a)/sizeof(*a);
	int start, end;
	int maxProfit=BestTimeBuySendStock(a, length, &start, &end);
	//printf("%d and %d and %d",start, end, maxProfit);
	assert(start==2);
	assert(end==3);
	assert(maxProfit==15);
}