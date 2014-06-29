#include <iostream>
#include <vector>

using namespace std;


void pritnVector(const vector<int> & a){
	cout<<"vector ";
	for (int i = 0; i < a.size(); ++i){
		cout<<a[i]<<" ";
	}
	cout<<endl;
}

void swap(vector<int> & a, int i, int j){

	int temp=a[i];
	a[i]=a[j];
	for (int k = j; k>=i+2; --k){
		a[k]=a[k-1];
	}
	a[i+1]=temp;
}	



void getMaxNumber(vector<int>& a, int n, int k){
	if(n<=1)
		return;

	int i=0;
	int maxi=0;
	int maxVal=a[i];
	
	while(i<n-1 && k>0){
		for(int j=1; j<=k && (i+j)<n ; j++){
			if(a[i+j]>maxVal){
				maxVal=a[i+j];
				maxi=i+j;
			}
		}
		
		if(maxi>0){
			swap(a, i, maxi);
		}
			
		k-=(maxi-i);
		i++;
	}
}


int main(int argc, char const *argv[]){
	
	vector<int> a={1,3,4,2,5,7,9};
	getMaxNumber(a, 7, 1);
	pritnVector(a);

	vector<int> b={1,3,4,2,5,7,9};
	getMaxNumber(b, 7, 2);
	pritnVector(b);


	vector<int> c={1,3,4,2,5,7,9};
	getMaxNumber(c, 7, 3);
	pritnVector(c);

	vector<int> d={1,3,4,0,5,7,9};
	getMaxNumber(d, 7, 3);
	pritnVector(d);

	vector<int> e={1,3,4,0,5,7,9};
	getMaxNumber(e, 7, 4);
	pritnVector(e);

	vector<int> f={9,8,7,6,5,4,3};
	getMaxNumber(f, 7, 4);
	pritnVector(f);

	return 0;
}