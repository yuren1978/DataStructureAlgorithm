//http://codercareer.blogspot.com/2012/02/no-33-maximums-in-sliding-windows.html
//Question: Given an array of numbers and a sliding window size, how to get the maximal numbers in all sliding windows?

#include <iostream>
#include <vector>
#include <deque>
#include <iterator>

using namespace std;

template <class T>
void display_container( const T& v ) {
	// display elements using method of choice
	std::copy(v.begin(), v.end(), ostream_iterator<typename T::value_type>(cout, "\n"));
}


vector<int> maxInWindows(int* numbers, int arraySize, int windowSize)
{		
	vector<int> maxInWindow;	
	deque<int> indexDequeue;
	if(arraySize>0)
	{
		indexDequeue.push_back(0);
		for (int i=1;  i<arraySize; i++) 
		{		
			int backOfQueue=indexDequeue.back();
			if(numbers[backOfQueue]<=numbers[i])				
				indexDequeue.pop_back();
			
			if(!indexDequeue.empty())
			{
				int frontOfQueue=indexDequeue.front();
				if(frontOfQueue<=i-windowSize)
					indexDequeue.pop_front();
			}
			indexDequeue.push_back(i);
			
			if(i-windowSize>=0)
			{
				maxInWindow.push_back(numbers[indexDequeue.front()]);
			}
		}		
	}
	return maxInWindow;
}


int main(int argc, char *argv[]) {
	int arr[] = {2, 3, 4, 2, 6, 2, 5, 1};
	int arraySize=sizeof(arr)/sizeof(*arr);
	vector<int> maxArrayInWindow= maxInWindows(arr,arraySize,3);
	display_container(maxArrayInWindow);
}