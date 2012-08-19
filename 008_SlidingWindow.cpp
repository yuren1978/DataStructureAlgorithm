//http://codercareer.blogspot.com/2012/02/no-33-maximums-in-sliding-windows.html
//Question: Given an array of numbers and a sliding window size, how to get the maximal numbers in all sliding windows?

#include <iostream>
#include <vector>
#include <deque>
#include <iterator>

using namespace std;


vector<int> maxInWindows(const vector<int>& numbers, int windowSize)
{
    vector<int> maxInSlidingWindows;
    if(numbers.size() >= windowSize && windowSize > 1)
    {
        deque<int> indices;

         for(int i = 0; i < numbers.size(); ++i)
        {
			 if(i>=windowSize){
				maxInSlidingWindows.push_back(numbers[indices.front()]);	
			}
            

            while(!indices.empty() && numbers[i] >= numbers[indices.back()])
                indices.pop_back();
			  //the number at the front is beyond the scope the current sliding window, and it should be popped off. 	
            if(!indices.empty() && indices.front() <= i - windowSize)
                indices.pop_front();

            indices.push_back(i);
        }
        maxInSlidingWindows.push_back(numbers[indices.front()]);
    }

    return maxInSlidingWindows;
}

template <class T>
void display_container( const T& v ) {
	// display elements using method of choice
	std::copy(v.begin(), v.end(), ostream_iterator<typename T::value_type>(cout, "\n"));
}

int main(int argc, char *argv[]) {
	static const int arr[] = {2, 3, 4, 2, 6, 2, 5, 1};
	vector<int> vec (arr, arr + sizeof(arr) / sizeof(arr[0]) );
	vector<int> maxArrayInWindow= maxInWindows(vec,3);
	display_container(maxArrayInWindow);
}