#include <vector>
#include <map>
#include <set>
#include <iostream>
#include <string>
#include <queue>
#include <cmath>
using namespace std;


std::string Solution(int n, int no, bool print) {
    std::vector<long long> pivot(n + 2, 0);
    for(int i = 1; i <= n + 1; ++i) {
        pivot[i] = pivot[i - 1] + std::pow(10, n - i + 1) * std::pow(26, i - 1);
    }
    if(print){
        cout<<endl;
        for(int i=0; i<=n+1; ++i){
            cout<< "i "<<i << " "<< pivot[i] <<endl;
        }
    }
 

    no %= pivot[n + 1];

    if(print)
        cout<<" no " <<no  <<endl;
    
    long num0s = 0;
    while(no < pivot[n - num0s]) 
        num0s++;

    if(print)
        cout<<" num0s " <<num0s<<endl;
    
    //  start with 00...0A..A: number of 0 is num0, number of A is n - num0;
    long remainder = no - pivot[n - num0s];

    if(print)
        cout<< "n "<<n <<" num0s " <<num0s<< "  pivot[n - num0s] "<<  pivot[n - num0s]<<endl;

    if(print)
        cout<<"  remainder "<<remainder<<endl;
    
    int right_part = remainder % int(pow(26, n - num0s));
    int left_part = remainder / int(pow(26, n- num0s));

    if(print)
        cout<<"left part "<<left_part<<" right part "<<right_part<<endl;
    
    std::string left;
    if(num0s) {
        left = std::to_string(left_part);
        while(left.size() < num0s) {
            left.insert(left.begin(), '0');
        }
    } else {
        left = "";
    }
    
    std::string right;
    do {
        char c = right_part % 26;
        right.insert(right.begin(), c + 'A');
        right_part /= 26;
    }while(right_part);
    
    if(print)
        cout<<"left "<<left<<" right "<<right<<endl;

    return left + right;
}

int main(int argc, char const *argv[])
{
    /* code */
    //cout<<" Test "<<endl;
    //cout<<"first " << Solution(5, 3) <<endl;
    //cout<<"second "<< Solution(5, 99999)<<endl;
    //cout<<"third "<< Solution(5, 100000)<<endl;
    cout<< "max integer " << INT_MAX<<endl;
    //cout<<"solution 5 1 "<< Solution(5, 1, false)<<endl;
    //cout<<"solution 5 3 "<< Solution(5, 3, false)<<endl;
    cout<<"solution 5 99999 "<< Solution(5, 99999, false)<<endl;
    cout<<"solution 5 100000 "<< Solution(5, 100000, false)<<endl;
    //cout<<"solution 5 100001 "<< Solution(5, 100001, false)<<endl;
    //cout<<"solution 5 100002 "<< Solution(5, 100002, false)<<endl;
    //cout<<"solution 5 110001 "<< Solution(5, 110001, false)<<endl;
    //cout<<"solution 5 2793611 "<< Solution(5, 2793611, false)<<endl;
    //cout<<"solution 5 7363359 "<< Solution(5, 7363359, false)<<endl;
    //cout<<"solution 5 7363360 "<< Solution(5, 7363360, false)<<endl;
    return 0;
}
