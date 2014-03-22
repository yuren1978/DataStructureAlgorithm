#include <stack>
#include <iostream>

using namespace std;

int main(int argc, char const *argv[])
{
	stack<int> s;
	s.push(1);
	s.push(2);
	for (int val:s){
		cout<<val<<endl;
	}
	return 0;
}