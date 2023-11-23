//
// Created by 阳寜 on 2023/11/23.
//
#include<bits/stdc++.h>

typedef long long ll;
using namespace std;
class Solution {
public:
    int countSquares(vector<vector<int>>& matrix) {
        vector<vector<int>> opt(matrix.size(),vector<int>(matrix[0].size(),0));
        int m = matrix.size();
        int n = matrix[0].size();
        int num = 0;
        for (int i = 0; i < m; ++i) {
            opt[i][0] = matrix[i][0];
            num += opt[i][0];
        }
        //注意此时i从1开始，不然可能会num加两次matrix[0][0]点，导致结果＋1
        for (int i = 1; i < n; ++i) {
            opt[0][i] = matrix[0][i];
            num += opt[0][i];
        }
        for (int i = 1; i < m; ++i) {
            for (int j = 1; j < n; ++j) {
                opt[i][j] = min(min(opt[i][j - 1], opt[i - 1][j]), opt[i - 1][j - 1]) + 1;
                if (matrix[i][j] == 0) opt[i][j] = 0;
                num += opt[i][j];
            }
        }
        return num;
    }
};
int main() {
    vector<vector<int>> matrix = {{1,0,1},{1,1,0},{1,1,0}};
    Solution solution;
    cout << solution.countSquares(matrix);
}