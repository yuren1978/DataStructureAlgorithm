//http://www.mitbbs.com/article_t/JobHunting/32190019.html
#include <iostream>
#include <string>

using namespace std;

//Greedy.
string intToRoman(int num) {
    romanMap[1000] = "M";
    
    romanMap[900] = "CM";
    romanMap[500] = "D";
    romanMap[400] = "CD";
    romanMap[100] = "C";
    
    romanMap[90] = "XC";
    romanMap[50] = "L";
    romanMap[40] = "XL";
    romanMap[10] = "X";

    romanMap[9] = "IX";
    romanMap[5] = "V";
    romanMap[4] = "IV";
    romanMap[1] = "I";

    string s;
    for(map<int, string>::reverse_iterator it = romanMap.rbegin(); it != romanMap.rend(); ++it) {
        while(num >= it -> first) {
            s += it -> second;
            num -= it -> first;
        }
    }
    return s;
}



int main(int argc, char *argv[]) {
	string romanLetter= intToRoman(1000);
    cout<<romanLetter<<endl;
}