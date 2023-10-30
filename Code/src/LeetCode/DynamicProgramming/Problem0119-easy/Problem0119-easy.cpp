//
// Created by 阳寜 on 2023/10/30.
//
#include<bits/stdc++.h>

using namespace std;
class Solution {
public:
    vector<int> getRow(int rowIndex) {
        //第n行共有n+1项，计算出第n行可以依此计算出第n+1行，因此
        //最简单的思路一行一行计算即可。
        vector<vector<int>> C(rowIndex + 1);
        for (int i = 0; i <= rowIndex; ++i) {
            C[i].resize(i + 1);
            C[i][0] = C[i][i] = 1;
            for (int j = 1; j < i; ++j) {
                C[i][j] = C[i - 1][j - 1] + C[i - 1][j];
            }
        }
        return C[rowIndex];
    }
};

int main() {


    return 0;
}
