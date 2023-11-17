//
// Created by 阳寜 on 2023/11/17.
//
#include<bits/stdc++.h>

typedef long long ll;
using namespace std;
class Solution {
public:
    int deleteAndEarn(vector<int>& nums) {
        int maxNum = * max_element(nums.begin(),nums.end());
        vector<int> sum(maxNum + 1);
        for(int n : nums) {
            sum[n] += n;
        }
        if (maxNum <= 1) return sum[1];
        vector<int> opt(maxNum + 1);
        opt[0] = 0;
        opt[1] = sum[1];
        opt[2] = max(sum[1],sum[2]);
        for (int i = 3; i <= maxNum; ++i) {
            opt[i] = max(opt[i - 1],opt[i - 2] + sum[i]);
        }
        return opt[maxNum];
    }
};