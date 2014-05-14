

	using namespace std;
	#include <vector>
	#include <iostream>

	using namespace std;



    bool isBounded(const vector<vector<char>> &board,vector<vector<bool>> &visited, int i, int j){
    	
       

        if(visited[i][j]) return true;

        int m=board.size();
        int n=board[0].size();

        bool bounded=false;

        visited[i][j]=true; 

        if ( 'X'== board[i][j] )  {    return  true;}

        if ( (i==0 || i==m-1 || j==0 || j==n-1) &&  'O'== board[i][j] )  {  return false;}

     
        
        return   (  isBounded(board, visited,i,j-1))
             && (  isBounded(board, visited,i, j+1))
             && (  isBounded(board, visited,i-1, j))
             && (  isBounded(board, visited, i+1, j ));
        
    }



    void solve(vector<vector<char>> &board) {
        int m=board.size();
        if(0==m) return ;
        int n=board[0].size();
        for(int i=1; i<m-1; i++){
       		for(int j=1; j<n-1; j++){
       			vector<vector<bool>> visited(m, vector<bool>(n, false));     
       			if('O'==board[i][j] && isBounded(board, visited, i, j) ) {
       				board[i][j]='X';
       			}
       			visited[i][j]=true;
       		}
        }
    }

    int main(int argc, char const *argv[])
    {
    	vector<vector<char>> plain{
    						 {'X','X','X','X','X'},
                             {'X','O','O','O','X'},
                             {'X','X','O','O','X'},
                             {'X','X','X','O','X'},
                             {'X','O','X','X','X'}
                         };               
                
        solve(plain);                 

        int m=plain.size();
        int n=plain[0].size();
        for (int i = 0; i < m; ++i){
        	for (int j = 0; j < n; ++j){
        		cout<<plain[i][j]<<" ";
        	}
        	cout<<endl;
        }
        
    	return 0;
    }