#include<map>
#include <iostream>
#include <set>
#include <cmath>
#include <string>
#include <vector>
#include <climits>
#include <algorithm>
using namespace std;

    void rotateCurrentCircle(vector<vector<int>>& matrix, int start){
        //value change
        //(0,0) -> (0,3)->(3,3)->(3,0) ->(0,0)
        //(0,1) -> (1,3)->(3,2)->(2,0) ->(0,1)
        //(0,2) -> (2,3)- (3,1)-(1,0) -> (0,2)
        //first:  i=j; j=size-i
        //second: i=j; j=size-i
        //third : i=j; j=size-i
        //fourth: i=j; j=size-i
        int size=matrix.size();
        int r=start; //r won't change
        for(int c=start; c<size-start-1; c++){ // c will change
            int tmp=matrix[r][c];
            matrix[r][c]=matrix[size-1-c][r];
            matrix[size-1-c][r]=matrix[size-1-r][size-1-c];
            matrix[size-1-r][size-1-c]=matrix[size-1-c][size-1-r];
            matrix[size-1-c][size-1-r]=tmp;
        }
    }

int main(int argc, char const *argv[])
{
    /* code */
    vector<vector<int>> matrix={{1,2,3}, {4,5,6}, {7,8,9}};
    rotateCurrentCircle(matrix , 0);
    return 0;
}
