//http://dl.dropbox.com/u/19732851/LeetCode/ReadMe.html
#include <stdio.h>

typedef enum {false, true} bool;

bool IsNumber(const char *s) 
{
    bool num = false;
    bool dot = false;   //decimal sign
    bool exp = false;   //exponential sign
    bool spa = false;   //space
    //trim spaces on left
    while(*s != '\0' && *s == ' ' ) ++s;
    //skip +/- sign
    if (*s!='\0' && (*s == '+' || *s == '-'))++s;

    while(*s != '\0')
    {
        if(*s == ' ') spa = true;
        else if(spa) return false; //space inside of non-space make number invalid
        
        else if (*s >= '0' && *s <= '9')
            num = true;
		
        else if(*s == 'e')
        {
            //exponential sign already exist, or no number in front
            //then invalid number.
            if(exp || !num) return false;
            exp = true;
			num = false; // need number after exponential sign, so make it false
        }
        else if(*s == '.')
        {
			//no decimal sign after exponential sign and decimal sign
            if(exp || dot) return false;
            dot = true;
        }
        else if(*s == '-' || *s == '+')
        {
			// +/- sign should only follow exponential sign
            if (*(s-1) != 'e') return false;
        }

        else //any other characters would make number invalid 
            return false;
        ++s;
    }


    return num;
}


int main(int argc, char** argv)
{
	char s1[] = "abc";
	char s2[] = "  +1.e-2  ";
	char s3[] = " .0e200";
	char s4[] = "0+00";
	
	printf("%s\n", IsNumber(s1)?"true":"false");
	printf("%s\n", IsNumber(s2)?"true":"false");
	printf("%s\n", IsNumber(s3)?"true":"false");
	printf("%s\n", IsNumber(s4)?"true":"false");
	
	return 0;
}