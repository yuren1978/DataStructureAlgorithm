
#include <iostream>
#include <vector>
#include <cassert>
#include <climits>

using namespace std;

bool inRange(int i, int j, int m, int n){
	return i>=0 && i<m && j>=0 && j<n ;
}

void dfsConnectedCount(vector< vector<int> >& v ,  int m, int n, int i, int j){
	if(!inRange(i,j,m,n) || v[i][j]==INT_MAX)
		return;

	if( v[i][j]==1){
		v[i][j]=INT_MAX;
		dfsConnectedCount(v, m, n, i-1, j);
		dfsConnectedCount(v, m, n, i, j-1);
		dfsConnectedCount(v, m, n, i+1, j);
		dfsConnectedCount(v, m, n, i, j+1);
	}	
}


int getConnectedCount(vector< vector<int> >& v , int m, int n){
	
	int count=0;
	for (int i = 0; i < m; ++i){
		for(int j=0; j<n; ++j){
			if(v[i][j]==1){
				dfsConnectedCount(v, m, n, i, j);
				count++;
			}	
		}
	}
	return count;
}

int maxInFour(int a, int b, int c, int d){
	return max(a, max(b, max(c,d)));
}


int dfsMaxDistance(vector< vector<int> >& v, int preValue, int m, int n, int i, int j){
	if(!inRange(i,j,m,n) || v[i][j]==INT_MIN || preValue>v[i][j] )
		return 0;

	int curValue=v[i][j];
	v[i][j]=INT_MIN;
	return 1+maxInFour(
			dfsMaxDistance(v, curValue, m, n, i-1, j),
			dfsMaxDistance(v, curValue,m, n, i+1,j),
			dfsMaxDistance(v, curValue, m, n, i, j-1),
			dfsMaxDistance(v, curValue, m, n, i, j+1)
		);
}

int getMaxDistance(vector< vector<int> >& v , int m, int n){
	int maxDistance=INT_MIN;
	for (int i = 0; i < m; ++i){
		for(int j=0; j<n; ++j){
			maxDistance=max(maxDistance,dfsMaxDistance(v, INT_MIN, m, n, i, j));
		}
	}
	return maxDistance;
}


void dfsSetMatrixCount(vector< vector<int> >& v , int m, int n, int i, int j, const int& count){
	if(!inRange(i,j,m,n) || v[i][j]<0)
		return;

	if( v[i][j]==1){
		v[i][j]=count;
		dfsSetMatrixCount(v, m, n, i-1, j, count);
		dfsSetMatrixCount(v, m, n, i, j-1, count);
		dfsSetMatrixCount(v, m, n, i+1, j, count);
		dfsSetMatrixCount(v, m, n, i, j+1, count);
	}	
}


int setMatrixCount(vector< vector<int> >& v ){
	
	int m=v.size();
	int n=v[0].size();
	int count=-1;
	for (int i = 0; i < m; ++i){
		for(int j=0; j<n; ++j){
			if(v[i][j]==1){
				dfsSetMatrixCount(v,m, n, i, j, count);
				count--;
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
			cout<< (v[i][j]<0 ? (0-v[i][j]):0) ;
			if(j!=n-1)
				cout<<",";
		}
		cout<<"}"<<endl;
	}
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


	vector< vector<int> > d =
	{
	    {4,3,9},
	    {6,5,1},
	    {7,8,2}
	};

	vector< vector<int> > e =
	{
	    {0, 0, 0, 0, 0, 1, 1, 0, 0, 0},
	    {1, 1, 0, 0, 1, 1, 0, 0, 0, 0},
	    {1, 1, 1, 0, 0, 1, 1, 0, 0, 0},
	    {0, 0, 0, 1, 1, 0, 0, 0, 0, 0 }
	};

	assert(3==getConnectedCount(a,3,3));
	assert(1==getConnectedCount(b,3,3));
	assert(2==getConnectedCount(c,7,12));

	cout<<getMaxDistance(d,3,3)<<endl;

	setMatrixCount(e);

	printmaxtirx(e);

	return 0;
}