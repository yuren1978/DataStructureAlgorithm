class Solution {
public:
    int lengthOfLastWord(const char *s) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        if(s==NULL) return 0;
        const char* l=s;
        const char* r=s;
        bool wordStart=false;
        while(*s!='\0'){
            if(*s==' '){
                if(wordStart){
                    wordStart=false;
                    r=s;
                }
            }
            else{
                if(!wordStart){
                     wordStart=true;
                     l=s;
                }
            }
            s++;
        }
        if(wordStart){
            return s-l;
        }
        return r-l;
    }
};