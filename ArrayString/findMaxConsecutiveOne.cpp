#include <vector>
#include <climits>
#include <iostream>
using namespace std;


 void moveFirstArray(vector<int>& nums, int end, int begin){
        for(int i=end; i>=begin; i--){
            nums[i]=nums[i-1];
        }
    }
    
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        int i=0, j=0;
        while(i<m && j<n){
            if(nums1[i]<=nums2[j]){//just move i
                i++;
            }
            else{
                moveFirstArray(nums1,m+j, i+1);
                nums1[i]=nums2[j];
                j++;
                i++;
                m++;
            }
        }
        while(j<n){
            nums1[i++]=nums2[j];
            j++;
        }
    }

int main(int argc, char const *argv[])
{
    /* code */
    vector<int> m={-1,3,0,0,0,0,0};
    vector<int> n={0,0,1,2,3};
    merge(m,2, n,5);
    for(int i=0; i<m.size(); i++){
        cout<< m[i]<<" ";
    }
    cout<<endl;
    return 0;
}
