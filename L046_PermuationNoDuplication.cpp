	#include <iostream>
	#include <vector>
	#include <algorithm>
	using namespace std;
	
	void printVector(vector<int> &num)
	{
		for (int i = 0; i < num.size(); ++i)
		{
			cout<<num[i];
		}
		cout<<endl;
	}

	void swap(vector<int> &num, int i, int j){
		if(i!=j){
			int temp=num[i];
			num[i]=num[j];
			num[j]=temp;
		}
	}

	void permute(vector<int> &num, int level, vector<vector<int> >& results){
		if(level==num.size()-1){
			//cout<<"Level "<<level<<" ";
			//printVector(num);
			results.push_back(num);
			return;
		}

		permute(num, level+1, results);
		for (int i = level+1; i < num.size(); ++i)
		{
			if(num[i]==num[i-1]||num[i]==num[level]){
				continue;
			}
			swap(num, i, level);
			permute(num, level+1, results);
			swap(num, level, i);
		}
	}

    vector<vector<int> > permute(vector<int> &num) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        vector<vector<int> > results;
        //sort(num.begin(),num.end());
        permute(num, 0, results);
        return results;

    }


    int main(int argc, char *argv[]) {
		vector<int> permutationVector;
		permutationVector.push_back(0);
		permutationVector.push_back(0);
		permutationVector.push_back(1);
		permutationVector.push_back(9);
		permute(permutationVector);
	}