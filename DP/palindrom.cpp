#include <string>
#include <vector>
#include <iostream>

using namespace std;


void printVector(const vector< vector<string> >& v){
	cout<<"print vector list"<<endl;
	for (const vector<string>& vc : v ){
		cout<<"vector "<<endl;
		for (const string& item : vc){
			cout<<item<<"  ";
		}
		cout<<endl;
	}

	cout<<endl;
	cout<<endl;
}

vector< vector<bool> > buildPartitionTable(const string& s){
	int n=s.size();
	vector< vector<bool> > partitionTable(n, vector<bool>(n, false));
	int step=0;
	while(step<n){
		for(int i=0; i<n-step; i++){
			int j=i+step;
			if(i==j)    partitionTable[i][j]=true;
			else if(j-i==1)	partitionTable[i][j]=(s[i]==s[j]);
			else partitionTable[i][j]= partitionTable[i+1][j-1] && (s[i]==s[j]);
		}
		step++;
	}
	return partitionTable;
}



vector< vector<string> > partitionHelper(const string& s, int start, const vector< vector<bool> > p){
	vector< vector<string> > v;
	
	int size=s.size();

	if(start==size)
		return v;

	for (int i = start; i < size; ++i){
		if(p[start][i]){//find one portion of string
			if(i==size-1){
				vector<string> cv;
				cv.push_back(s.substr(start, i-start+1));
				v.push_back(cv);
			}
			else{
				vector< vector<string> > otherPortions=partitionHelper(s, i+1, p);
				for (auto& otherPortion:otherPortions){
					otherPortion.insert(otherPortion.begin(), s.substr(start, i-start+1));
					v.push_back(otherPortion);
				}
			}
		}
	}
	return v;
}


vector< vector<string> > partition(string s){
	vector< vector<string> > v;
	if(s.length()==0)
		return v;
	vector< vector<bool> >  partitionTable=buildPartitionTable(s);		
	v=partitionHelper(s, 0, partitionTable );
	return v;
}


int main(int argc, char const *argv[])
{
	// vector< vector<string> > v1=partition("");
	// printVector(v1);
	// vector< vector<string> > v2=partition("a");
	// printVector(v2);
	// vector< vector<string> > v3=partition("ab");
	// printVector(v3);
	// vector< vector<string> > v4=partition("aab");
	// printVector(v4);
	vector< vector<string> > v5=partition("aabbaa");
	printVector(v5);
	return 0;
}