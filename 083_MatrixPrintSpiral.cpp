#include <iostream>
#include <cstdlib>
#include <cassert>

#define N_MAX 4 

using namespace std;



void print_spiral(int mat[][N_MAX], int m, int n, int k) {
  if (m <= 0 || n <= 0)
    return;
  if (m == 1) {
    for (int j = 0; j < n; j++)
      cout << mat[k][k+j] << " ";
    return;
  }
  if (n == 1) {
    for (int i = 0; i < m; i++)
      cout << mat[k+i][k] << " ";
    return;
  }
  // print from top left
  for (int j = 0; j < n - 1; j++)
    cout << mat[k][k+j] << " ";
  // print from top right
  for (int i = 0; i < m - 1; i++)
    cout << mat[k+i][k+n-1] << " ";
  // print from bottom right
  for (int j = 0; j < n - 1; j++)
    cout << mat[k+m-1][k+n-1-j] << " ";
  // print from bottom left
  for (int i = 0; i < m - 1; i++)
    cout << mat[k+m-1-i][k] << " ";
 
  print_spiral(mat, m-2, n-2, k+1);
}
 
void print_spiral_helper(int mat[][N_MAX], int m, int n) {
  print_spiral(mat, m, n, 0);
}

void print_spiral_nonrecursive(int a[][N_MAX], int m, int n) {
int T, t = 0;
int rowStrt = 0, rowEnd = n-1;
int colStrt = 0, colEnd = m-1;

while (rowStrt <= rowEnd) {
if (rowStrt == rowEnd) { /// Only 1 row
for (int j=colStrt; j<=colEnd; j++)
printf("%d ", a[rowStrt][j]);
break;
}

if (colStrt == colEnd) { /// Only 1 col
for (int i=rowStrt; i<=rowEnd; i++)
printf("%d ", a[i][colStrt]);
break;
}

for (int j=colStrt; j<colEnd; j++)
	printf("%d ", a[rowStrt][j]);

for (int i=rowStrt; i<rowEnd; i++)
	printf("%d ", a[i][colEnd]);

for (int j=colEnd; j>colStrt; j--) 
	printf("%d ", a[rowEnd][j]);

for (int i=rowEnd; i>rowStrt; i--)
	printf("%d ", a[i][colStrt]);

colStrt++, colEnd--;
rowStrt++, rowEnd--;
printf("\nrowStrt = %d, rowEnd = %d\n", rowStrt, rowEnd);
}
fprintf(stderr, "Time execute: %.3lf\n", clock() / (double)CLOCKS_PER_SEC);

}


int main(int argc, char *argv[]) {
	int a[4][4]={
		{1,2,8,9},
		{2,4,9,12},
		{4,7,10,13},
		{6,8,11,15}
	};
	//print_spiral_helper(a,4,4);
	print_spiral_nonrecursive(a,4,4);
}