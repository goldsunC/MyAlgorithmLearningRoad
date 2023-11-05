//
// Created by 阳寜 on 2023/11/5.
//
#include<bits/stdc++.h>

using namespace std;
class Solution {
public:
    int findChampion(vector<vector<int>>& grid) {
        int camp = 0;
        for (int i = 0; i < grid.size(); ++i) {
            int num = 0;
            int j = 0;
            for (; j < grid[0].size(); ++j) {
                if (i == j) {
                    continue;
                }
                if (grid[i][j] == 1) {
                    num++;
                }
            }
            if (num == grid.size() - 1) {
                camp = i;
            }
        }
        return camp;
    }
};
int main() {
    vector<vector<int>> grid = {{0,0,1},{1,0,1},{0,0,0}};
    Solution solution;
    cout << solution.findChampion(grid);
    return 0;
}
