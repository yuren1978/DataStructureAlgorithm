//http://zhedahht.blog.163.com/blog/static/25411174200952174133707/
//题目：输入一个正整数数组，将它们连接起来排成一个数，输出能排出的所有数字中最小的一个。例如输入数组{32,  321}，
//则输出这两个能排成的最小数字32132。请给出解决问题的算法，并证明该算法。

#include <iostream>
#include <vector>
#include <climits>
#include <string>

using namespace std;

void exchange(int& num1, int& num2){
	int temp=num1;
	num1 = num2;
	num2 = temp;
}

int getCurrentNumber(const vector<int>& numbers){
	string s;
	for(auto num: numbers){
		s+= to_string(num);
	}
	return stoi(numbers);
}


void getMinNumber(vector<int>& numbers, int start, int& minNumber){
	int size=numbers.size();
	if(start==size){
		int currentNumber=getCurrentNumber(numbers);
		minNumber=min(minNumber,currentNumber);
		return;
	}
	
	for(int i=start; i<size; i++){
		exchange(numbers[start], numbers[i]);
		getMinNumber(numbers, start+1, minNumber);
		exchange(numbers[i], numbers[start]);
	}
}

int main(int argc, char *argv[]) {
	int minNumber=INT_MAX;
	getMinNumber(numbers, 0, minNumber);
	cout<<minNumber<<endl;
}