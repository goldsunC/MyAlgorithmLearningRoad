//
// Created by 阳寜 on 2023/10/30.
//
#include<bits/stdc++.h>

using namespace std;

class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        vector<vector<long long>> opt(obstacleGrid.size(),vector<long long>(obstacleGrid[0].size(),0));
        if(obstacleGrid[obstacleGrid.size() - 1][obstacleGrid[0].size() - 1] == 1) return 0;
        if(obstacleGrid[0][0] == 1) return 0;
        opt[0][0] = 1;
        for (int i = 1; i < obstacleGrid.size(); i++) {
            if(obstacleGrid[i-1][0] == 1) break;
            opt[i][0] = 1;

        }
        for (int i = 1; i < obstacleGrid[0].size(); i++) {
            if(obstacleGrid[0][i-1] == 1) break;
            opt[0][i] = 1;
        }
        for (int i = 1; i < obstacleGrid.size(); i++) {
            for (int j = 1; j < obstacleGrid[0].size(); j++) {
                opt[i][j] = opt[i][j-1] + opt[i-1][j];
                if (obstacleGrid[i-1][j] == 1) {
                    opt[i][j] = opt[i][j-1];
                }
                if (obstacleGrid[i][j-1] == 1) {
                    opt[i][j] = opt[i-1][j];
                }
                if (obstacleGrid[i][j-1] == 1 && obstacleGrid[i-1][j] == 1) {
                    opt[i][j] = 0;
                }
            }
        }
        return opt[obstacleGrid.size() - 1][obstacleGrid[0].size() - 1];
    }
};


int main() {
    vector<vector<int>> obstacleGrid = {{0,0,0,0},{0,1,0,0},{0,0,1,0},{0,0,0,0}};
    Solution solution;
    cout << solution.uniquePathsWithObstacles(obstacleGrid);
    return 0;
}
