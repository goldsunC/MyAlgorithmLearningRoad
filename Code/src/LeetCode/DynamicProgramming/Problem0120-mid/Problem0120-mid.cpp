//
// Created by 阳寜 on 2023/11/17.
//
#include<bits/stdc++.h>

typedef long long ll;
using namespace std;
class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        int ans = INT_MAX;
        vector<vector<int>> opt(triangle.size(),vector<int> (triangle.size(),0));
        opt[0][0] = triangle[0][0];

        for (int i = 1; i < triangle.size(); ++i) {
            opt[i][0] =opt[i-1][0] + triangle[i][0];
        }
        for (int i = 1; i < triangle.size(); ++i) {
            opt[i][i] =opt[i-1][i-1] + triangle[i][i];
        }
        for (int i = 1; i < triangle.size(); ++i) {
            for (int j = 1; j < i; ++j) {
                opt[i][j] = min(opt[i - 1][j - 1] ,opt[i - 1][j] )+ triangle[i][j];
            }
        }
        for (int i = 0; i < triangle.size(); ++i) {
            ans = min(ans,opt[triangle.size() - 1][i]);
        }
        return ans;
    }
};

int main() {
    Solution solution;
    vector<vector<int>> tri = {{2},{3,4},{6,5,7},{4,1,8,3}};
    cout << solution.minimumTotal(tri);
}