class Solution {
public:
void makeRotation(vector<vector<int> > &matrix,int startRow, int startCol, int endRow, int endCol){
    int step=0;
    while(startCol+step < endCol){
            int temp=matrix[startRow][startCol+step];
            matrix[startRow][startCol+step]=matrix[endRow-step][startCol];
            matrix[endRow-step][startCol]=matrix[endRow][endCol-step];
            matrix[endRow][endCol-step]=matrix[startRow+step][endCol];
            matrix[startRow+step][endCol]=temp;
            step++; 
        }
 
}
   
    void rotate(vector<vector<int> > &matrix) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        int n=matrix.size();
        int startRow=0; int startCol=0;
        int endRow=n-1; int endCol=n-1;
        while(startRow<endRow){
            
          
            makeRotation(matrix, startRow, startCol, endRow, endCol);
           startRow++; 
            startCol++;
            
            endRow=n-1-startRow;
            endCol=n-1-startCol;
        }
    }
};