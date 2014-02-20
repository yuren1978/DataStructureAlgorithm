//http://www.leetcode.com/2010/11/best-time-to-buy-and-sell-stock.html
// was given an interview question on this, but they had a following question: if you can keep buying and selling, how to maximize the profit? for example, if it is 6,1,3,2,4,7, we can buy for 1 and sell for 3, and we can buy for 2, and sell for 4,then buy on 4, sell for 7. total maxval =3-1+4-2+7-4 = 7. They would like to have some O(n) solutions
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

int maxProfit(vector<int> &prices)
{
	//get the differences between ajacent pair
	vector<int> priceDiffrences;
	int length=prices.size();
	int diffLength=length-1;
	for (int i=1; i<length; ++i) {
		priceDiffrences=prices[i]-prices[i-1];
	}	
	int maxProfit=INT_MIN;
	int sum=0;
	for (int i=0; i<diffLength; ++i) {
		sum+=priceDiffrences[i];
		if(sum<0){
			sum=0;
		}
		if(sum>maxProfit){
			maxProfit=sum;
		}		
	}
}

int main(int argc, char *argv[]) {	
	int maxProfit=BestTimeBuySendStock(a, length, &start, &end);
	//printf("%d and %d and %d",start, end, maxProfit);
	//assert(start==2);
	//assert(end==3);
	//assert(maxProfit==15);
}