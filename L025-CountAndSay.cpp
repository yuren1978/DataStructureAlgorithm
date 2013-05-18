//The idea is simple, compare the current char in the string with the previous one, if they are the same, count +1, if not, print the previous char (count + char), set the new char and count, until the string ends.
//Note that the the ascii code of '0' is 48, to convert the int to char we can use "char chr = i + '0';"

#include <iostream>

using namespace std;

string cas(string str){
        string str1;
        char ch=str[0];
        int chn=1;
		//cout<<str<<endl;
		//cout<<ch<<endl;
		//cout<<str.size()<<endl;
        for(int i = 1; i<=str.size();i++){
			//cout<<str[i]<<endl;
			//cout<<ch<<endl;
          
		  if (str[i]==ch)
			{
				chn++;
			}
            else {
                char chr = chn+'0';
                str1 += chr;
				cout<<str1<<endl;
                str1 += ch;
				cout<<str1<<endl;
                ch = str[i];
                chn=1;
            }
        }
        return str1;
    }

string countAndSay(int n) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        if (n==1) {return "1";}
        string str1 = "1";
        string strn;
        for (int i=1; i<n;i++){
            strn = cas(str1);
			//cout<<strn<<endl;
            str1 = strn;
        }
        return strn;
    }

int main(int argc, char *argv[]) {
	string s=countAndSay(3);
	//cout<<s<<endl;
}