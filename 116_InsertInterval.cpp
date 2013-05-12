#include <iostream>
#include <vector>

using namespace std;


struct Interval {
    int start;
    int end;
    Interval() : start(0), end(0) {}
    Interval(int s, int e) : start(s), end(e) {}
};
  bool CompareInterval(Interval& currentInterval, Interval& newInterval){
        if(currentInterval.end<newInterval.start){
            return -1;
        }
        else if(currentInterval.start>newInterval.end){
            return 1;
        }
        else{
            newInterval.start=currentInterval.start<newInterval.start?currentInterval.start:newInterval.start;
            newInterval.end=currentInterval.end>newInterval.end?currentInterval.end:newInterval.end;
            
            return 0;
        }
    }
 
 
 vector<Interval> insert(vector<Interval> &intervals, Interval newInterval) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        //sort(intervals.begin(), intervals.end(), sortI);
        vector<Interval> mergeIntervals;
        int size=intervals.size();
        bool newIntervalInserted=false;
		cout<<"test"<<endl;
        for(int i=0; i<size; i++){
            Interval currentInterval=intervals[i];
            if(CompareInterval(currentInterval, newInterval)<0){
                mergeIntervals.push_back(currentInterval);
			    cout<<"push current"<<endl;
            }
            else if(CompareInterval(currentInterval, newInterval)>0){
                if(!newIntervalInserted){
                    mergeIntervals.push_back(newInterval);
                    newIntervalInserted=true;
                }
                 mergeIntervals.push_back(currentInterval);
            }
        }
        if(!newIntervalInserted){
               mergeIntervals.push_back(newInterval);
				cout<<"push new"<<endl;
        }
        return mergeIntervals;
    }

int main(int argc, char *argv[]) {
	vector<Interval> intervals;
	intervals.push_back(*(new Interval(1,5)));
	vector<Interval> inserted= insert(intervals, *(new Interval(6,8)));
	for (int i=0; i<inserted.size(); i++) {
		cout<<inserted[i].start<<endl;
	}
	
}