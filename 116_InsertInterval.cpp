#include <iostream>
#include <vector>

using namespace std;


struct Interval {
    int start;
    int end;
    Interval() : start(0), end(0) {}
    Interval(int s, int e) : start(s), end(e) {}
};

int CompareInterval(const Interval& interval1, Interval& interval2){
	if(interval1.end<interval2.start){
		return -1;
	}
	else if(interval1.start>interval2.end){
		return 1;
	}
	else {
		interval2.start=interval1.start<interval2.start?interval1.start:interval2.start;
		interval2.end=interval1.end>interval2.end?interval1.end:interval2.end;
		return 0;
	}
}	

 vector<Interval> insert(vector<Interval> &intervals, Interval newInterval) {
    vector<Interval> mergedIntervals;
	 int size=intervals.size();          
	 
	 for (int i=0; i<size; ++i) {
		Interval current=intervals[i];
		int compareResult=CompareInterval(newInterval, current);
        if(compareResult<0){
			mergedIntervals.push_back(newInterval);
            for(int j=i; j<size; ++j){
                Interval current=intervals[j];
    	        mergedIntervals.push_back(current);
            }
			return mergedIntervals;
			//add the remaining intervals.
		}else if(compareResult>0){
			mergedIntervals.push_back(current);
		}
        
        
	}
    
        mergedIntervals.push_back(newInterval);
        return mergedIntervals;

     
}

int main(int argc, char *argv[]) {
	
}