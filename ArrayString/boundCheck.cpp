// lower_bound and upper_bound in vector
#include <algorithm> // for lower_bound, upper_bound and sort
#include <iostream>
#include <vector> // for vector

using namespace std;

int main()
{
    vector<int> v{ 4, 5, 6, 7, 7, 6, 5, 5, 6};
	sort(v.begin(), v.end()); // 5 5 5 6 6 6 7 7

	vector<int>::iterator lower, upper;
	lower = lower_bound(v.begin(), v.end(), 4);
	upper = upper_bound(v.begin(), v.end(), 6);

    cout<<"lower bound "<< *lower<<endl;
    cout<<"upper bound "<< *upper<<endl;    
	return 0;
}


class Solution {
public:
    bool valid(vector<vector<char>>& board , int r, int c){
        int m=board.size();
        int n=board[0].size();

        for(int i=0; i<m; i++){
            if(i==r)
                continue;
            if(board[i][c]==board[r][c]){
                cout<< board[i][c] <<endl;
                return false;
            }       
        }

        for(int i=0; i<n; i++){
            if(i==c)
                continue;
            if(board[r][i]==board[r][c]){
                cout<< board[r][i] <<endl;
                return false;
            }
        }

        for(int i=(r/3)*3; i<(r/3)*3+3; i++){
            for(int j=(c/3)*3; j<(c/3)*3+3; j++){
                if(i==r && j==c)
                    continue;
                if(board[i][j]==board[r][c]){
                    cout<< board[i][j] <<endl;
                    return false;
                }
                    
            }
        }
        return true;
    }

    bool isValidSudoku(vector<vector<char>>& board) {
        int m=board.size();
        int n=board[0].size();
        for(int i=0; i<m; i++){
            for(int j=0; j<n; j++){
                if(board[i][j]=='.')
                    continue;
                if(!valid(board, i, j)){

                    cout<<" i "<<i<<" j "<<j<<" "<<board[i][j]<< endl;
                    return false;
                }
                    
            }
        }
        return true;    
    }
};