#include <fstream>
#include <iostream>
#include <deque>
#include <iomanip>
#include <sstream>
#include <string>
#include <algorithm>

using namespace std;

string addBinary(string a, string b) {
        // IMPORTANT: Please reset any member data you declared, as
        // the same Solution instance will be reused for each test case.
        int sizeA=a.size();
        int sizeB=b.size();
        int c=0;
        int i=0;
        string sum;
        while(i<sizeA || i<sizeB || c>0){
            int numA= i<sizeA? a[i]-'0':0;
            int numB= i<sizeB? b[i]-'0':0;
            int numSum=(numA+numB+c)%2;
            sum += (numSum+'0');
            cout<<"current sum"<<sum <<endl;
            c=(numA+numB+c)/2;
            i++; //move forward
        }
        std:reverse(sum.begin(), sum.end());
        return sum;
    }

    int main(){
    	string sum=addBinary("1010","1011");
    	cout<<sum<<endl;
    	return 0;
    }
    