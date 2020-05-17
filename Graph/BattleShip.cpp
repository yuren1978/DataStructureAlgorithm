#include <vector>
#include <iostream>
using namespace std;

class Point
{
public:
    int X;
    int Y;
    Point(int x, int y){
        X=x;
        Y=y;
    };
};


vector<vector<Point>> getBattershipCoordinates(const vector<vector<char>>& batterships){
    vector<vector<Point>>  points;
    int m=batterships.size();
    int n=batterships[0].size();
    int count=0;
    for(int i=0; i<m; i++){
        for(int j=0; j<n; j++){
            if(batterships[i][j]=='X'){
                if((i-1>=0 && batterships[i-1][j]=='X')
                || (j-1>=0 && batterships[i][j-1]=='X')){//continue last battership
                    points[count-1].push_back(Point(i,j));
                }
                else{
                    vector<Point> pv { Point (i,j) };
                    points.push_back(pv);
                    count++;
                }
            }
        }
    }
    return points;
}

int main(int argc, char const *argv[])
{
    vector<vector<char>> batterShips={
        {'X','.','.','X'},
        {'.','.','.','X'},
        {'.','.','.','X'}
    } ;
    vector< vector<Point> > points=getBattershipCoordinates(batterShips);
    for (const auto& batterShip : points)
    {
        for(const auto& point: batterShip){
            cout<<" X "<<point.X <<" Y "<<point.Y;
        }

        cout<<"new battership"<<endl;
    }
    

    return 0;
}
