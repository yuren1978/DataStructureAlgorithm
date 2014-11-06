#include <iostream>
#include <string>
#include <vector>

using namespace std;

 	string getPermutation(int n, int k) {
        //initialize the string.
        vector<int> numbers;
        int mod=1;
        for(int i=1; i<=n; i++){
            numbers.push_back(i);
            mod=mod*i;
        }

        for(auto& num : numbers){
        	cout<<num<<endl;
        }

        cout<<"mod "<<mod<<endl;



        k--; 
        
        string permutationString;
        
        for(int i=0; i<n; i++){
            mod=mod/(n-i);

            int currentIndex=k/mod;
            k=k%mod;
            
            cout<<"mod "<< mod << " current index "<<currentIndex<<endl;

            int currentNumber=numbers[currentIndex];
            permutationString +=to_string(currentNumber);
            numbers.erase(std::remove(numbers.begin(), numbers.end(), currentNumber), numbers.end());
        }
        return permutationString;
    }

int main(int argc, char const *argv[])
{
	cout<< getPermutation(3,3) <<endl;
	return 0;
}