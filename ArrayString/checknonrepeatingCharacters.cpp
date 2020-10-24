#include <unordered_map>
#include <vector>
#include <string>
#include <stack>
#include <set>
#include <map>
#include <algorithm>
using namespace std;

  string mostCommonWord(string paragraph, vector<string>& banned) {
        std::transform(paragraph.begin(), paragraph.end(), paragraph.begin(),[](unsigned char c){ return std::tolower(c); });
        string mostFrequentWord;
        int wordFrequency=-1;
        set<string> bannedSet;
        map<string, int> wordFrequencty;
        for(const string& word: banned){
            bannedSet.insert(word);
        }
        int left=0, right=0;
        int i=0;
        int size=paragraph.size();
        while(i<size){
            while(i<size && !isalpha(paragraph[i])){
                i++;
            }
            left=i;
            i=left+1;
            while(i<size && isalpha(paragraph[i])){
                i++;
            }
            right=i;
            if(right>left){
                string word=paragraph.substr(left, right-left);
                if(!bannedSet.count(word)){
                    wordFrequencty[word]++;
                    if(wordFrequencty[word]>wordFrequency){
                        mostFrequentWord=word;
                    }
                }
            }
        }
        return mostFrequentWord;
    }

int main(int argc, char const *argv[])
{
    /* code */
    string paragraph="Bob hit a ball, the hit BALL flew far after it was hit.";
    vector<string> hitWords={{"hit"}};
    string  mostFrequentWord=mostCommonWord(paragraph,hitWords );
    return 0;
}
