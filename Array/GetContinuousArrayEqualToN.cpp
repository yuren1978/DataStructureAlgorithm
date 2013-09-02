//http://zhedahht.blog.163.com/blog/static/25411174200732711051101/
//题目：输入一个正数n，输出所有和为n连续正数序列。
//例如输入15，由于1+2+3+4+5=4+5+6=7+8=15，所以输出3个连续序列1-5、4-6和7-8。

#include <cstdio>
#include <iostream>
#include <vector>

using namespace std;


void PrintContinuousSequence(const vector<int>& v){
      for(int i = 0; i < v.size(); ++ i)
            printf("%d ", v[i]);
      printf("\n");
}



vector<int> getVector(int small, int big){
	vector<int> v;
	for (int i = small; i <= big; ++i){
		v.push_back(i);
	}
	return v;
}

vector< vector<int> > FindContinuousSequence(int n){
	
	vector< vector<int> > v;
	if(n<3) return v;

	int small=1; int big=2;
	int middle=n/2;
	int sum=small+big;
	while(small<=middle){
		if(sum==n){
			v.push_back(getVector(small,big));
			sum-=small;	
			small++;
		}
		else if(sum<n){
			big++;
			sum+=big;
		}
		else if(sum>n){
			sum-=small;
			small++;
		}
	}
	return v;
}

int main(int argc, char *argv[]) {
	int n=15;
	vector< vector<int> >  sumVectors = FindContinuousSequence(n);
	int size=sumVectors.size();
	for (int i = 0; i < size; ++i){
		PrintContinuousSequence(sumVectors[i]);
	}
}