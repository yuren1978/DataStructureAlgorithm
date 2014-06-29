#include <iostream>
#include <vector>

using namespace std;


int main(int argc, char const *argv[])
{
	const int N = 100;
	int dimes[] = { 1, 2, 5, 10 };
	int arr[N + 1] = { 1 };
	for (int i = 0; i < sizeof(dimes) / sizeof(int); ++i)
	{
	    for (int j = dimes[i]; j <= N; ++j)
	    {
	    	cout<<"j - "<<j <<" j - dimes[i] - "<< j - dimes[i] <<endl;
	        arr[j] += arr[j - dimes[i]];
	    }
	}
	return 0;
}

