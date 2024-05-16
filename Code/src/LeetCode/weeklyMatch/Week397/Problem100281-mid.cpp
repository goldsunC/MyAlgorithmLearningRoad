//
// Created by 阳寜 on 2024/5/12.
//
#include<bits/stdc++.h>

typedef long long ll;
using namespace std;
class Solution {
public:
    int maxScore(vector<vector<int>>& grid) {
        int m = grid.size(),n = grid[0].size();
        vector<vector<int>> dp(m,vector<int>(n,0));
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                dp[i][j] = grid[i][j];
            }
        }
        dp[0][0] = -100001;
        for (int i = 1; i < m; ++i) {
            dp[i][0] = max(grid[i][0] - grid[i - 1][0] + dp[i - 1][0],grid[i][0] - grid[i - 1][0]);
        }
        for (int i = 1; i < n; ++i) {
            dp[0][i] = max(grid[0][i] - grid[0][i - 1] + dp[0][i - 1],grid[0][i] - grid[0][i - 1]);
        }

        for (int i = 1; i < m; ++i) {
            for (int j = 1; j < n; ++j) {
                int a = max(dp[i - 1][j] + grid[i][j] - grid[i - 1][j],dp[i][j - 1] + grid[i][j] - grid[i][j-1]);
                int b = max(grid[i][j] - grid[i - 1][j],grid[i][j] - grid[i][j-1]);
                dp[i][j] = max(a,b);
            }
        }
        int ans = INT_MIN;
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                ans = max(ans,dp[i][j]);
            }
        }
        return ans;
    }
};

int main() {
    Solution solution;
    vector<vector<int>> grid = {{9,5,7,3},{8,9,6,1},{6,7,14,3},{2,5,3,1}};
    solution.maxScore(grid);
}