#include <iostream>
using namespace std;

bool equalString(const string& s1, const string& s2, int size){
  for (int i = 0; i < size; ++i){
    if(s1[i]!=s2[i])
       return false;
  }
  return true;
}

bool computeDuplidates(const string& prefix, int length, int& startSize, int startIndex){ //compute duplicate for this line
   
   int nextStartSize=startSize;
   int halfLength=length/2;
   bool misMatch=false;
   bool foundMatch=false;
   for (int size = startSize; size <= halfLength; ++size){
       misMatch=false;
      if(length%size==0){
          string segment=prefix.substr(0, size);
          int start=max(startIndex, size) ;
          do{
              string currentSegment=prefix.substr(start,size);
              //cout<<"segment -"<<segment<<"  currentSegment-"<<currentSegment<<endl;
              if(!equalString(segment,currentSegment, size)){
                  misMatch=true;
                  break;
              }
              start+=size;
          }while(start<=length-size);
          //come here, print a solution and exit.
          if(!misMatch){
            nextStartSize=size;
            foundMatch=true;
            cout<<length<<" "<<(length/size)<<endl;
            break;
          }
      }
   }
   startSize=nextStartSize;
   if(foundMatch){
      //cout<<"found match"<<endl;
   }
   return foundMatch;
}

void processCurrentLine(int size, const string& currentLine){
    if(size>1){
        int startSize=1;
        int startIndex=0;
        for(int i=2; i<=size; i++){
           string prefix=currentLine.substr(0, i);
           if(i%startSize==0){
              //cout<<"start size "<< startSize<<" and start index "<<startIndex <<" and prefix "<<prefix<<endl;
              if(computeDuplidates(prefix,i, startSize, startIndex)){//we found a match
                  startIndex=i;
                  //cout<<"start Index " <<startIndex<<endl;
              }
          }
        }
    }
}

int  main()
{
    int n;
    cin >> n;
    string currentLine;
    int count=0;
    while(n>0){
      if (std::getline(std::cin >> std::ws, currentLine)) {
          cout<<"Test case #"<<++count<<endl;
          processCurrentLine(n, currentLine); 
      }
      else {
          // deal with a failure to read another line
          cout<<"wrong input"<<endl;
      }
      cin>>n;
    }
    return 0;
}