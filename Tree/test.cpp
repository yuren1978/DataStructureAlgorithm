#include <vector>
#include <iostream>

using namespace std;

int main(){
	vector<int> v;
	v.push_back(1);
	for(int i: v){
		cout<<i<<endl;
	}
	return 0;
}