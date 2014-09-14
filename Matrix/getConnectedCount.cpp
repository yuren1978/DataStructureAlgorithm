
#include <iostream>
#include <vector>

using namespace std;

bool inRange(int i, int j, int m, int n){
	return i>=0 && i<m && j>=0 && j<n ;
}

void dfs(vector< vector<int> >& v , vector< vector<bool> >& mark,  int m, int n, int i, int j, const int& count){
	if(!inRange(i,j,m,n) || mark[i][j])
		return;

	if( v[i][j]==1){
		mark[i][j]=true;
		v[i][j]=count;
		dfs(v, mark, m, n, i-1, j, count);
		dfs(v, mark, m, n, i, j-1, count);
		dfs(v, mark, m, n, i+1, j, count);
		dfs(v, mark, m, n, i, j+1, count);
	}	
}


int getConnectedCount(vector< vector<int> >& v ){
	
	int m=v.size();
	int n=v[0].size();
	int count=1;
	vector< vector<bool> > mark(m, vector<bool>(n, false));
	for (int i = 0; i < m; ++i){
		for(int j=0; j<n; ++j){
			if(v[i][j]==1 && !mark[i][j]){
				dfs(v, mark,m, n, i, j, count);
				count++;
			}	
		}
	}
	return count;
}

void printmaxtirx(const vector< vector<int> >& v ){
	int m=v.size();
	int n=v[0].size();
	for(int i=0; i<m; i++){
		cout<<"{";
		for(int j=0; j<n;j++){
			cout<<v[i][j];
			if(j!=n-1)
				cout<<",";
		}
		cout<<"}"<<endl;
	}
}

int main(int argc, char const *argv[])
{

	vector< vector<int> > c =
	{
	    {0, 0, 0, 0, 0, 1, 1, 0, 0, 0},
	    {1, 1, 0, 0, 1, 1, 0, 0, 0, 0},
	    {1, 1, 1, 0, 0, 1, 1, 0, 0, 0},
	    {0, 0, 0, 1, 1, 0, 0, 0, 0, 0 }
	};
	getConnectedCount(c);
	printmaxtirx(c);
	return 0;
}