#include <iostream>
#include <vector>
using namespace std;


size_t find(const vector<int>& array, int key){
	auto l=array.begin();
	auto r=array.end()-1;

	while(l<r){
		auto mid=l+(r-l)/2;
		if(key==*mid) return mid-array.begin();
		if(key<*mid) r=mid-1;
		else l=mid+1;
	}
	return l-array.begin();
}

 
int main(){
	vector<int> v={10,20,30};
	cout<<find(v, 40)<<endl;
}
