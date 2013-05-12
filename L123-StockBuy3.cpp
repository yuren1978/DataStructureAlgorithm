#include <iostream>

using namespace std;
int main(int argc, char *argv[]) {
	
}

class Solution {
public:
    int maxProfit(vector<int> &prices) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        int size=prices.size();
        if(size==0 || size==1) return 0;
        vector<int> diff(size-1);
        for(int i=0; i<size-1; i++){
            diff[i]=prices[i+1]-prices[i];
        }
        //Get left Max
        vector<int> left(size);
        int sum=0;
        int leftMax=0;
        left[0]=0;
        
        for(int i=1; i<size; i++){
            sum+=diff[i-1];
            if(sum<0){
                sum=0;
            }
            if(sum>leftMax){
                leftMax=sum;
            }
            left[i]=leftMax;
        }
        //Get right Max
        vector<int> right(size);
        sum=0;
        int rightMax=0;
        right[size-1]=0;
        for(int i=size-2; i>=0; i--){
            sum+=diff[i];
            if(sum<0){
                sum=0;
            }
            if(sum>rightMax){
                rightMax=sum;
            }
            right[i]=rightMax;
        }
        //Get max profits
        int max=0;
        for(int i=0; i<size; i++){
            if(left[i]+right[i]>max){
                max=left[i]+right[i];
            }
        }
        return max;
    }
};