#include <vector>
#include <stack>
#include <string>
#include <iostream>
using namespace std;


void printVector(const vector<int>& numbers){
    cout<<"========="<<endl;
    for(int i=0; i<numbers.size(); i++){
        cout<<" "<<numbers[i]<<" "<<endl;
    }
    cout<<"========="<<endl;
}

vector<int> canSeePersonsCount(vector<int>& heights) {
        stack<int> ms;
        int size = heights.size();
        vector<int> rightHigher(size, -1);
        for(int i=size-1; i>=0; i--){
           int currentHeight = heights[i];
           int count=0; 
           while(!ms.empty() &&  heights[ms.top()]<currentHeight)  {
               //cout<<" current height "<<currentHeight << " current height of top stack element "<<heights[ms.top()]<<endl;
               ms.pop();
               count++;
           }
            //set the right higher
            rightHigher[i]=ms.empty()?-1: ms.top();
            cout<<" right higher of "<<i<< " is "<<rightHigher[i]<<" pop count " <<count <<endl;
           ms.push(i);
        }
        return rightHigher;
    }

int main(int argc, char const *argv[])
{
    // 0, 1, 2, 3, 4, 5
    //10, 6, 8, 5,11, 9
    vector numbers = {10,6,8,5,11,9};
    //printVector(numbers);
    canSeePersonsCount(numbers);
    return 0;
}
