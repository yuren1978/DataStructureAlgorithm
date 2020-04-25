#include <vector>
#include <queue>
using namespace std;


int shortestDistance(vector<vector<int>> grid) {
    int m = grid.size(), n = grid[0].size();
    auto total = grid;
    int walk = 0, mindist, delta[] = {0, 1, 0, -1, 0};
    for (int i=0; i<m; ++i) {
        for (int j=0; j<n; ++j) {
            if (grid[i][j] == 1) {
                mindist = -1;
                auto dist = grid;
                queue<pair<int, int>> q;
                q.emplace(i, j);
                while (q.size()) {
                    auto ij = q.front();
                    q.pop();
                    for (int d=0; d<4; ++d) {
                        int di = ij.first + delta[d];
                        int dj = ij.second + delta[d+1];
                        if (di >= 0 && di < m && dj >= 0 && dj < n && grid[di][dj] == walk) {
                            grid[di][dj]--;
                            dist[di][dj] = dist[ij.first][ij.second] + 1;
                            total[di][dj] += dist[di][dj] - 1;
                            q.emplace(di, dj);
                            if (mindist < 0 || mindist > total[di][dj])
                                mindist = total[di][dj];
                        }
                    }
                }
                walk--;
            }
        }
    }
    return mindist;
}


int main(int argc, char const *argv[])
{
    /* code */
    vector< vector<int> > buildings ={
        {1,0,2,0,1},
        {0,0,0,0,0},
        {0,0,1,0,0}
    };
    return shortestDistance(buildings);
    return 0;
}
