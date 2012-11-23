//http://www.mitbbs.com/article_t/JobHunting/32190019.html
#include <iostream>

using namespace std;

string intToRoman(int num) {
    string table[] = {"M", "CM","D","CD","C","XC","L","XL","X","IX","V","IV","I"};
    int   values[] = {1000,900,500,400,100,90,50,40,10,9,5,4,1};
    string result;
    for(int iter = 0; iter < 13;)
    {
        if(num >= values[iter])
        {
            result += table[iter];
            num -= values[iter];
        }
        else
            ++iter;
    }
    return result;
}



int main(int argc, char *argv[]) {
	
}