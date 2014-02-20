bool canJump(int A[], int n){
	int i=0;
	int m=0;
	while(i<=m){
		m=m>i+A[i]?m:i+A[i];
		if(m>=n-1) break;
		i++;
	}
	return m>=n-1;
}


int int main(int argc, char const *argv[])
{
	/* code */
	return 0;
}