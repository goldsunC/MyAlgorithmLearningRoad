//
// Created by 阳寜 on 2023/11/20.
//
#include<bits/stdc++.h>

typedef long long ll;
using namespace std;
class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        vector<int> opt(nums.size());
        opt[0] = nums[0];
        for (int i = 1; i < nums.size(); ++i) {
            opt[i] = max(opt[i - 1] + nums[i], nums[i]);
        }
        return *max_element(opt.begin(),opt.end());
    }
};