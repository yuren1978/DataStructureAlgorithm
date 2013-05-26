
#include <iostream>
#include <vector>

 int uniquePaths(int m, int n) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
 	vector< vector<int> > vMatrix(m, vector<int>(n,0));  
 	for (int i = 1; i < m; ++i)
 	{
 		for (int j = 1; i < n; ++i)
 		{
 			/* code */
 		}
 	}

  	return vMatrix[m-1][n-1];      
  }


  int main(){
  	int number=uniquePaths(3,7);
  	return 0;
  }