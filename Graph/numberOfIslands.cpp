#include <vector>
#include <queue>
#include <iostream>
using namespace std;


void bfs(vector<vector<char>>& grid, int i, int j, int m, int n){
        queue<pair<int, int>> q;
        q.push({i,j});
        while(!q.empty()){
            auto top=q.front();
            q.pop();
            int r=top.first;
            int c=top.second;
            grid[r][c]='2'; //visited
            if(r-1>=0 && grid[r-1][c]=='1')
                q.push({r-1,c});
            if(r+1<=m-1 && grid[r+1][c]=='1')
                 q.push({r+1,c});
            if(c-1>=0 && grid[r][c-1]=='1')
                 q.push({r,c-1});
            if(c+1<=n-1 && grid[r][c+1]=='1')
                q.push({r,c+1});
        }
    }
    
    int numIslands(vector<vector<char>>& grid) {
        int numOfIslands=0;
        int m=grid.size();
        if(m==0) return 0;
        int n=grid[0].size();
        if(n==0) return 0;
        for(int i=0; i<m; i++)
            for(int j=0; j<n; j++){
                if(grid[i][j]=='1'){
                    bfs(grid,i, j, m, n);
                    numOfIslands++;
                }
            }
        return numOfIslands;
    }


int main(int argc, char const *argv[])
{

     vector<vector<char>> batterShips={
        {'1','1','1','1','0'},
        {'1','1','0','1','0'},
        {'1','1','0','0','0'},
        {'0','0','0','0','0'}};
    int numberOfIslands=numIslands(batterShips);
    cout<<numberOfIslands<<endl;
    /* code */
    return 0;
}
