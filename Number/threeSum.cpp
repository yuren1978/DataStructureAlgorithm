#include <iostream>
#include <vector>
#include <cassert>
#include <algorithm>

using namespace std;







    vector<vector<int> > threeSum(vector<int> &num) {
        vector<vector<int> > v;
        int size=num.size();
        if(size<3)
            return vector<vector<int>>();

        sort(num.begin(), num.end());

        bool forward=false;
        bool backward=true;
        for (int i = 0; i < size-2; ++i){
            int j=i+1;
            int k=size-1;
            while(j<k){
                if(forward && num[j]==num[j-1]) {j++; continue;}
                if(backward && num[k]==num[k+1]) {k--; continue;}    

                if(num[i]+num[j]+num[k]==0){
                    vector<int> currentV;
                    currentV.push_back(num[i]);
                    currentV.push_back(num[j]);
                    currentV.push_back(num[k]);
                    v.push_back(currentV);  
                    j++;
                    k--;
                }
                else if(num[i]+num[j]+num[k]<0){
                    forward=true;
                    j++;
                }
                else{
                    backward=true;
                    k--;
                }
            }
        }
        return v;
    }

int main(int argc, char const *argv[])
{
    /* code */
    return 0;
}