#include <iostream>
#include <queue>
#include <utility>
#include <map>
#include <set>


//BFS to get min number
using namespace std;

int getMinNumberPress(int choices[], int size, int target){
	queue<pair<int,int> > q;
	int step=1;
	for(int i=0; i<size; i++){
		q.push(make_pair(choices[i], step));
	}

	while(!q.empty()){
		
		pair<int, int> top = q.front();
		q.pop();
		
		if(top.first==target)
			return top.second;
		else{
			for(int i=0; i<size; i++){
				q.push(make_pair(top.first+choices[i], top.second+1));
			}
		}

	}
	return -1;
}


int main(int argc, char const *argv[]){
		/* code */
	int a[]={-10, -5, -1, 1, 5, 10};
	cout<<getMinNumberPress(a, 6, 16)<<endl;
	return 0;
}	