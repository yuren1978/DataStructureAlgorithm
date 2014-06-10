#include <iostream>
#include <string>
#include <vector>


using namespace std;


bool getWordsOnLine(const vector<string> &words,  int wordStart, int& wordEnd, int L){
    	int wordCount=words.size();
    	int lineLength=0;
    	
    	while(lineLength<L && wordStart<=wordCount-1){
    		
    		lineLength+=words[wordStart].size();
    		
        	if(lineLength>=L){
    			if(lineLength==L) 
    				wordStart++;
    			break;	
    		}
    
    		lineLength++;
    		wordStart++;
    	}
    	
    	wordEnd=wordStart-1;
    
    	return wordStart<wordCount;
    }

    
    string makeLine(const vector<string> &words,  int wordStart, int wordEnd, int L, bool lastLine){
    	string line;
    	int wordSize=0;
    	for (int i = wordStart; i <= wordEnd; ++i){
    		wordSize += words[i].size();
    	}
    	int spaceLength=L-wordSize;
    	int spaceCount=wordEnd-wordStart;
    	
    	if(spaceCount==0){
    		line +=words[wordStart];
    		line.append(L-words[wordStart].size(),' ');
    		return line;
    	}
    
    	if(lastLine){
			while(wordStart<=wordEnd){
	    		line.append(words[wordStart]);
	    		line.append(1,' ');
	    		spaceLength--;
	    		wordStart++;
	    	}
	    	line.append(spaceLength,' ');
    	}
    	else{
    		while(spaceCount>0){
	    		line.append(words[wordStart]);
	    		int currentSpace=spaceLength%spaceCount==0? (spaceLength/spaceCount):(spaceLength/spaceCount)+1;
	    		line.append(currentSpace,' ');
	    		spaceLength -= currentSpace;
	    		wordStart++;
	    		spaceCount--;
	    	}
	    	line.append(words[wordEnd]);
    	}
    	
    	
    	return line;
    }


    vector<string> fullJustify(vector<string> &words, int L) {
        vector<string> texts;
        
        if(words.size()==0) return words;
        if(L==0) return words;
        
    	int wordStart=0;
    	int wordEnd=0;
    	while(getWordsOnLine(words, wordStart, wordEnd, L)){
    		string currentLine= makeLine(words, wordStart,wordEnd, L, false);
    		//cout<<currentLine<<endl;
    		texts.push_back(currentLine);
    		wordStart=wordEnd+1; //get another line starting from next.
    		//cout<<wordStart<<endl;
    	}
    	//add the final line
    	string currentLine= makeLine(words, wordStart,wordEnd, L, true);
    	//cout<<currentLine<<endl;
    	texts.push_back(currentLine);
    	return texts;
    }

int main(int argc, char const *argv[])
{
	vector<string> v {"What","must","be","shall","be."};
	vector<string> justifiedLines=fullJustify(v, 12);
	for(auto s : justifiedLines){
		cout<<s<<endl;
	}
	return 0;
}