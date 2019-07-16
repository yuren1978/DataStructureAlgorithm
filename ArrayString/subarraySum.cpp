#include <vector>
using namespace std;

int static subarraySum(vector<int>& nums, int k) {
         int count=0;
        int i=0; 
        int j=0;
        int currentSum=nums[i];
        int size=nums.size();
        while(j<size){
            if(currentSum==k){
                count++;
                if(j==size-1)
                    break;
                if(i<j){
                    currentSum -=nums[i];
                    i++;
                }
                else{
                    j++;
                    if(j<size)
                        currentSum +=nums[j];
                }
            }
            else if(currentSum<k){
                j++;
                if(j<size)
                    currentSum +=nums[j];
            }
            else if(currentSum>k){
                currentSum -=nums[i];
                i++;
                if(i>j){//reset j
                    j=i;   
                }
            }
        }
        //j reach to end
        while(i<j-1){
            currentSum -=nums[i];
            if(currentSum==k){
                count++;
            }
            i++;
        }
        return count;
    }


int main(int argc, char const *argv[])
{
    /* code */
    vector<int> v{-1,-1, 1};
    int count= subarraySum(v, 0);
    return 0;
}
