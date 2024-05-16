//
// Created by 阳寜 on 2024/5/11.
//
#include<bits/stdc++.h>

typedef long long ll;
using namespace std;
class Solution {
public:
    bool satisfiesConditions(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        if (m == 1 && n == 1) return true;
        if (m == 1) {
            for (int i = 0; i < n - 1; ++i) {
                if (grid[0][i] == grid[0][i+1]) return false;
            }
            return true;
        }
        if (n == 1) {
            for (int j = 0; j < m - 1; ++j) {
                if (grid[j][0] != grid[j+1][0]) return false;
            }
            return true;
        }

        for (int i = 0; i < n - 1; ++i) {
            for (int j = 0; j < m - 1; ++j) {
                if (grid[0][i] == grid[0][i+1] || grid[j][0] != grid[j+1][0]) return false;
            }
        }
        for (int i = 0; i < n - 1; ++i) {
            if (grid[m-1][i] == grid[m-1][i+1]) return false;
        }
        for (int j = 0; j < m - 1; ++j) {
            if (grid[j][n-1] != grid[j+1][n-1]) return false;
        }
        return true;
    }
};
