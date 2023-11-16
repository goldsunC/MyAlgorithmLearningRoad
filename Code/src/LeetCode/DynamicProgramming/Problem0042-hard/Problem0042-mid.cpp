//
// Created by 阳寜 on 2023/11/16.
//
#include<bits/stdc++.h>

typedef long long ll;
using namespace std;

class Solution {
public:
    int trap(vector<int>& height) {
        int n = height.size();
        if (n <= 2) {
            return 0;
        }
        int ans = 0;
        vector<int> preMax(n),afterMax(n);
        preMax[0] = 0;
        afterMax[n - 1] = 0;
        for (int i = 1; i < n; ++i) {
            preMax[i] = max(preMax[i - 1], height[i - 1]);
        }
        for (int i = n - 2; i >= 0; --i) {
            afterMax[i] = max(afterMax[i + 1],height[i + 1]);
        }
        for (int i = 1; i < n - 1; ++i) {
            int minHeight = min(preMax[i],afterMax[i]);
            if (minHeight - height[i] > 0) {
                ans += minHeight - height[i];
            }
        }
        return ans;
    }
};