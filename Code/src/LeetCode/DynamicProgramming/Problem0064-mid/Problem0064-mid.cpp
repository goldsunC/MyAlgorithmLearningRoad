//
// Created by 阳寜 on 2023/11/13.
//
#include<bits/stdc++.h>

using namespace std;
class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        if (grid.size() == 0 || grid[0].size() == 0) {
            return 0;
        }
        vector<vector<int>> opt(grid.size(),vector<int> (grid[0].size()));
        opt[0][0] = grid[0][0];
        for (int i = 1; i < grid.size(); ++i) {
            opt[i][0] = opt[i-1][0] + grid[i][0];
        }
        for (int i = 1; i < grid[0].size(); ++i) {
            opt[0][i] = opt[0][i-1] + grid[0][i];
        }
        for (int i = 1; i < grid.size(); ++i) {
            for (int j = 1; j < grid[0].size(); ++j) {
                opt[i][j] = min(opt[i-1][j],opt[i][j-1]) + grid[i][j];
            }
        }
        return opt[grid.size()-1][grid[0].size()-1];
    }
};
int main() {
    return 0;
}
