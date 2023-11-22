//
// Created by 阳寜 on 2023/11/22.
//
#include<bits/stdc++.h>

typedef long long ll;
using namespace std;
class Solution {
public:
    int minPathCost(vector<vector<int>>& grid, vector<vector<int>>& moveCost) {
        int m = grid.size();
        int n = grid[0].size();
        vector<vector<int>> opt(m,vector<int>(n));
        for (int i = 0; i < n; ++i) {
            opt[0][i] = grid[0][i];
        }
        for (int i = 1; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                int minCost = INT_MAX;
                for (int k = 0; k < n; ++k) {
                    minCost = min(minCost,opt[i-1][k] + moveCost[grid[i-1][k]][j] + grid[i][j]);
                }
                opt[i][j] = minCost;
            }
        }
        return *min_element(opt[m-1].begin(),opt[m-1].end());
    }
};
int main() {
    vector<vector<int>> grid = {{5,3},{4,0},{2,1}};
    vector<vector<int>> moveCost = {{9,8},{1,5},{10,12},{18,6},{2,4},
                                    {14,3}};
    Solution solution;
    cout << solution.minPathCost(grid,moveCost);
}