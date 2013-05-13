#include <iostream>

using namespace std;

 int minPathSum(vector<vector<int> > &grid) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        int m=grid.size();
        int n=grid[0].size();
        int* minGrid=new int[m*n];
        
        int sum=0;
        for(int i=0; i<n; i++){
            sum+=grid[0][i];
            minGrid[i]=sum;
        }
        
        sum=0;
        for(int i=0; i<m; i++){
            sum+=grid[i][0];
            minGrid[i*n]=sum;
        }
        
        for(int i=1; i<m; i++){
            for(int j=1; j<n; j++){
                int pathFromLeft=minGrid[i*n+j-1]+grid[i][j];
                int pathFromTop=minGrid[(i-1)*n+j]+grid[i][j];
                minGrid[i*n+j]=pathFromLeft<pathFromTop?pathFromLeft:pathFromTop;
            }
        }
        
        return minGrid[m*n-1];
    }

int main(int argc, char *argv[]) {
	
}