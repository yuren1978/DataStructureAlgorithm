#include <iostream>
#include <vector>

using namespace std;

void fillInBorder(vector<vector<int> >& matrix, int& value, int startRow, int startCol, int endRow, int endCol){
	for (int i=startCol; i<endCol; i++) {
		matrix[startRow][i]=value++;
	}
	for (int i=startRow; i<endRow; i++) {
		matrix[i][endCol]=value++;
	}
	for(int i=endCol; i>startCol; i--){
		matrix[endRow][i]=value++;
	}
	for (int i=endRow; i>startRow; i--) {
		matrix[i][startCol]=value++;
	}
}

vector<vector<int> > generateMatrix(int n) {
    // Start typing your C/C++ solution below
    // DO NOT write int main() function
	vector<vector<int> > v= vector<vector<int> >(n);
	for (int i=0; i<n; i++) {
		v[i]=vector<int>(n);
	}
	
	int startRow=0; int startCol=0; int endRow=n-1; int endCol=n-1;
	int value=1;
	while (startRow<endRow) {
		fillInBorder(v, value, startRow, startCol, endRow, endCol);
		startRow++;endRow--; startCol++; endCol--;
	}
	if(startRow==endRow){
		v[startRow][endRow]=value;
	}
	return v;        
}

int main(int argc, char *argv[]) {
	
}