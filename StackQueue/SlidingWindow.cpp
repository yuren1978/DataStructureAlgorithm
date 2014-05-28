//http://codercareer.blogspot.com/2012/02/no-33-maximums-in-sliding-windows.html
//http://www.mitbbs.com/article_t1/JobHunting/32156867_0_1.html
//Question: Given an array of numbers and a sliding window size, how to get the maximal numbers in all sliding windows?
//用一个queue，第一个数总保持最大的值,每当读一个新数，如果当前最大数过了window，就pop，然后如果当前的数小于最后的数，push进去。如果当前的数大于尾巴， 把尾巴干掉。


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
		indexDequeue.push_back(0); //push in first index.
		for (int i=1;  i<arraySize; i++) 
		{		
			
			if(numbers[indexDequeue.back()]<=numbers[i])	// if current number is larger than tail, get rid of tail.			
				indexDequeue.pop_back();
			
			if(!indexDequeue.empty() && indexDequeue.front()<=i-windowSize)
				indexDequeue.pop_front();
			
			indexDequeue.push_back(i);

			if(i>=windowSize-1)
			{
				maxInWindow.push_back(numbers[indexDequeue.front()]);
			}
		}		
	}
	//display_container(maxInWindow);
	return maxInWindow;
}


int main(int argc, char *argv[]) {
	int arr[] = {2, 3, 4, 2, 6, 2, 5, 1};
	int arraySize=sizeof(arr)/sizeof(*arr);
	vector<int> maxArrayInWindow= maxInWindows(arr,arraySize,3);
	display_container(maxArrayInWindow);
}