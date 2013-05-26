#include <iostream>
#include <vector>

 int uniquePaths(int m, int n) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
 	 vector< vector<int> > vMatrix(m, vector<int>(n,0));
        
        if(m==0 || n==0) return 1;
        for(int i=0; i<m; i++){
            vMatrix[i][0]=1;
        }
        for(int i=0; i<n; i++){
            vMatrix[0][i]=1;
        }
        
        
  
        for (int i = 1; i < m; ++i){
      	for (int j = 1; j < n; ++j){
     			vMatrix[i][j]=vMatrix[i-1][j]+vMatrix[i][j-1];
     		}
     	}
    
      	return vMatrix[m-1][n-1];       
  }


  int main(){
  	int number=uniquePaths(3,7);
  	return 0;
  }
