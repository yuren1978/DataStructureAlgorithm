#include <vector>
#include <iostream>

using namespace std;

vector<char> multiplyArrays(const vector<char> &data1, const vector<char> &data2, int k) {
    int sz1 = data1.size();
    int sz2 = data2.size();
    vector<char> result(sz1+sz2,0);

    for(int i=sz1-1; i>=0; --i) {
        char carry = 0;
        
        for(int j=sz2-1; j>=0; --j) {
            char value = data1[i] * data2[j]+result[i+j+1]+carry;  
            
            carry = value/10;            
            result[i+j+1] = value % 10;
        }

        result[i]=carry;
    }
    if(sz1+sz2>k){
        vector<char> lastKElements(result.begin()+(sz1+sz2-k), result.end());
        return lastKElements;
    }
    else
        return result;
}



vector<char> calculate(unsigned long m, unsigned long n, int k) {
    if(n == 0) {
        return vector<char>(1, 1);
    } else if(n % 2) { // odd number
        vector<char> tmp(1, m);
        vector<char> result1 = calculate(m, n-1, k);
        return multiplyArrays(result1, tmp, k);
    } else {
        vector<char> result1 = calculate(m, n/2, k);
        return multiplyArrays(result1, result1, k);
    }
}

int main(int argc, char const *argv[]){


    vector<char> v=calculate(5,1234566789893943,1000);
    for(auto c : v){
        cout<<static_cast<unsigned>(c);
    }

}