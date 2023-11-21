//
// Created by 阳寜 on 2023/11/14.
//
#include<bits/stdc++.h>

using namespace std;

class Solution {
public:
    int numSquares(int n) {
        vector<int> opt(n + 1);
        for (int i = 1; i <= n; ++i) {
            int minn = INT_MAX;
            for (int j = 1; j*j <= i; ++j) {
                minn = min(minn, opt[i - j*j]);
            }
            opt[i] = minn + 1;
        }
        return opt[n];
    }
};
