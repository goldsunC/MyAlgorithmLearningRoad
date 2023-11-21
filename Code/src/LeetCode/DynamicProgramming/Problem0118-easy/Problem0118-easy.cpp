//
// Created by 阳寜 on 2023/11/21.
//
#include<bits/stdc++.h>

typedef long long ll;
using namespace std;
class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> ans;
        ans.push_back(vector<int>(1,1));
        if (numRows == 1) return ans;
        ans.push_back(vector<int>(2,1));
        if (numRows == 2) return ans;
        for (int i = 2; i < numRows; ++i) {
            vector<int> iRow;
            iRow.push_back(1);
            for (int j = 1; j < i; ++j) {
                iRow.push_back(ans[i-1][j-1] + ans[i-1][j]);
            }
            iRow.push_back(1);
            ans.push_back(iRow);
        }

        return ans;
    }
};
int main(){
    Solution solution;
    solution.generate(5);
}