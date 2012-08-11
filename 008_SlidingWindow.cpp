//http://codercareer.blogspot.com/2012/02/no-33-maximums-in-sliding-windows.html
//Question: Given an array of numbers and a sliding window size, how to get the maximal numbers in all sliding windows?

#include <iostream>
#include <vector>
#include <deque>

using namespace std;


vector<int> maxInWindows(const vector<int>& numbers, int windowSize)
{
    vector<int> maxInSlidingWindows;
    if(numbers.size() >= windowSize && windowSize > 1)
    {
        deque<int> indices;

        for(int i = 0; i < windowSize; ++i)
        {
            while(!indices.empty() && numbers[i] >= numbers[indices.back()])
                indices.pop_back();

            indices.push_back(i);
        }

        for(int i = windowSize; i < numbers.size(); ++i)
        {
            maxInSlidingWindows.push_back(numbers[indices.front()]);

            while(!indices.empty() && numbers[i] >= numbers[indices.back()])
                indices.pop_back();
            if(!indices.empty() && indices.front() <= i - windowSize)
                indices.pop_front();

            indices.push_back(i);
        }
        maxInSlidingWindows.push_back(numbers[indices.front()]);
    }

    return maxInSlidingWindows;
}

int main(int argc, char *argv[]) {
	static const int arr[] = {2, 3, 4, 2, 6, 2, 5, 1};
	vector<int> vec (arr, arr + sizeof(arr) / sizeof(arr[0]) );
	vector<int> maxArrayInWindow= maxInWindows(vec,3);
}