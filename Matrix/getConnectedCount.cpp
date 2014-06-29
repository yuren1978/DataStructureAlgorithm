
#include <iostream>
#include <vector>

using namespace std;

bool inRange(int i, int j, int m, int n){
	return i>=0 && i<m && j>=0 && j<n ;
}

void dfs(const vector< vector<int> >& v , vector< vector<bool> >& mark,  int m, int n, int i, int j){
	if(!inRange(i,j,m,n) || mark[i][j])
		return;

	if( v[i][j]==1){
		mark[i][j]=true;
		dfs(v, mark, m, n, i-1, j);
		dfs(v, mark, m, n, i, j-1);
		dfs(v, mark, m, n, i+1, j);
		dfs(v, mark, m, n, i, j+1);
	}	
}


int getConnectedCount(const vector< vector<int> >& v , int m, int n){
	
	int count=0;
	vector< vector<bool> > mark(m, vector<bool>(n, false));
	for (int i = 0; i < m; ++i){
		for(int j=0; j<n; ++j){
			if(v[i][j]==1 && !mark[i][j]){
				dfs(v, mark,m, n, i, j);
				count++;
			}	
		}
	}
	return count;
}


int main(int argc, char const *argv[])
{
	vector< vector<int> > a =
	{
	    {1,0,1},
	    {0,1,0},
	    {1,1,1}
	};

	vector< vector<int> > b =
	{
	    {1,1,1},
	    {0,0,1},
	    {1,1,1}
	};


	vector< vector<int> > c =
	{
	    {1,1,1,1,1,1,1,1,1,1,1,1},
	    {0,0,0,0,0,0,0,0,0,0,0,1},
	    {1,1,1,0,0,0,0,0,0,0,0,1},
	    {1,0,0,0,0,0,1,0,0,0,0,1},
	    {1,0,0,0,0,0,0,0,0,0,0,1},
	    {1,0,0,0,0,0,0,0,0,0,0,1},
		{1,1,1,1,1,1,1,1,1,1,1,1}
	};



	cout<<getConnectedCount(a,3,3)<<endl;
	cout<<getConnectedCount(b,3,3)<<endl;
	cout<<getConnectedCount(c,7,12)<<endl;
	return 0;
}