#include <iostream>
#include <vector>

using namespace std;


void spiralWalk(vector<vector<int> > &matrix, vector<int>& v, int startRow, int startCol, int endRow, int endCol){
	//top
	for(int i=startCol; i<endCol; i++){
		v.push_back(matrix[startRow][i]);
	}
	//right
	for(int i=startRow; i<endRow; i++){
		v.push_back(matrix[i][endCol]);
	}
	//bottom
	for(int i=endCol; i>startCol; i--){
		v.push_back(matrix[endRow][i]);
	}
	//left
	for(int i=endRow; i>0; i--){
		v.push_back(matrix[i][startCol]);
	}
}


    vector<int> spiralOrder(vector<vector<int> > &matrix) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
            vector<int> v;
		if(matrix.size()==0) return v; 
        int startRow=0; int endRow=matrix.size()-1;
		int startCol=0; int endCol=matrix[0].size()-1;
		
		while (startRow<endRow && startCol<endCol) {
			spiralWalk( matrix, v, startRow, startCol, endRow, endCol);
			startRow++; endRow--; startCol++; endCol--;
		}
		
		if(startRow==endRow && startCol==endCol){
			v.push_back(matrix[startRow][startCol] );
		}
		else {
			if(startRow==endRow){
				for (int i=startCol; i<=endCol; i++) {
					v.push_back(matrix[startRow][i]);
				}
			}
			else if(startCol==endCol) {
				for (int i=startRow; i<=endRow; i++) {
					v.push_back(matrix[i][startCol]);
				}
			}
		}
		return v;

    }
};

int main(int argc, char *argv[]) {
	
}