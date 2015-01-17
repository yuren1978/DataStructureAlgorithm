    #include <iostream>
    #include <cstdlib>
    #include <cstdio>


    using namespace std;     


    bool isMatch(const char *s, const char *p) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
         
        const char* star=NULL;
        const char* ss=s; 
        while (*s){
            if ((*p=='?')||(*p==*s)){
                cout<<"matched "<< *p<<*s<<endl;
                s++;p++;continue;
            }
            if (*p=='*'){
                star=p++; ss=s;continue;
            }
            if (star){ 

                cout<<"star met"<<endl;
                cout<<star<<endl;
                cout<<s<<endl;

                p = star+1; s=++ss;continue;
            }
            return false;
        }
        while (*p=='*'){p++;}
        return !*p;
    }

    int main(int argc, char const *argv[])
    {
        cout<<isMatch("abcf","a*c")<<endl;
    }