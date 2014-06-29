#include <vector>
#include <string>
#include <iostream>

using namespace std;

vector<string> printDotStr(string s)
{
    int len = s.length();
    vector<string> v;
    
    for(int i=1; i<= len-1; i++)
    {
        for(int j=len-1; j>=i; j--)
        {
            int k = i;
            string s1= s;
            int jj = j;
            while(k>0)
            {
                s1.insert(jj,1, '.');
                jj = jj-1;
                k--;
            }
            cout<<s1<<endl;
            v.push_back(s1);
        }
        cout<<endl;
    }
    return v;
}


int main(int argc, char const *argv[])
{
    printDotStr("0123456789");
}