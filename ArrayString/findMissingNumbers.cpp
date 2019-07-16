#include <vector>
#include <cmath>
#include <iostream>
using namespace std;

vector<int> findDisappearedNumbers(vector<int>& nums) {
        vector<int> disappearedNumbers;
        int length=nums.size();
        for(int i=0; i<length; i++){
            int currentNum=abs(nums[i]);
            if(nums[currentNum-1]>0)
                nums[currentNum-1]=0-nums[currentNum-1];
        }
        for(int i=0; i<length; i++){
            if(nums[i]>0){
                disappearedNumbers.push_back(i+1);
            }
        }
        return disappearedNumbers;
    }


int main(int argc, char const *argv[])
{
    /* code */ 
    vector<int> numers {4,3,2,7,8,2,3,1};
    vector<int> missingNumbers=findDisappearedNumbers(numers);
    for(int num: missingNumbers){
        cout<<num<<endl;
    }
    return 0;
}
