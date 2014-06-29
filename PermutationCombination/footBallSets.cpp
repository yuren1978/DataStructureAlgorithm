#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

void generateScoreMap(int totalScore,
		 int currentScore, 
		 vector<int>& scoreVector,
		 int start,
		 unordered_map<int, int>& scoreMap,
		 vector<unordered_map<int, int>>& scoreMaps){
	
	int size=scoreVector.size();

	if(currentScore>totalScore)
		return;

	if(currentScore==totalScore){
		scoreMaps.push_back(scoreMap);
		return;
	}

	for (int i = start; i < size; ++i){
		int ballScore=scoreVector[i];
		currentScore +=ballScore;
		scoreMap[ballScore]++;
		generateScoreMap(totalScore,currentScore, scoreVector, i,  scoreMap, scoreMaps);
		scoreMap[ballScore]--;
		currentScore -=ballScore;
	}
}


int main(int argc, char const *argv[])
{
	vector< unordered_map<int, int> > scoreMaps; //score is 1, 2, and 6
	unordered_map<int,int> scoreMap{
		{1,0},
		{2,0},
		{6,0}
	};
	vector<int> scoreVector {1,2,6};
	int start=0;
	int currentScore=0;
	generateScoreMap(10, currentScore, scoreVector, start, scoreMap, scoreMaps);



	for (auto& currentMap : scoreMaps){
		cout<< "solutions :" ;
		for (auto& item: currentMap){
			cout<< " [ "<< item.first<<" - "<<item.second << " ]" ;	
		}
		cout<<endl;
	}

	return 0;
}