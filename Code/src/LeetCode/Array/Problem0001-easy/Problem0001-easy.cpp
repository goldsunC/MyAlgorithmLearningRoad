//
// Created by 阳寜 on 2024/3/19.
//
#include<bits/stdc++.h>

typedef long long ll;
using namespace std;

/*
 * 思路：一定不能排序，因为需要返回的是下标，如果排序的话下标会被打乱。直接遍历即可，
 * 时间复杂度为n * n
 * */
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        int index = 0;
        vector<int> ans;
        for (int now = nums[index]; index < nums.size() - 1; now = nums[++index]) {
            for (int j = index + 1; j < nums.size(); ++j) {
                if (target - now == nums[j]) {
                    ans.emplace_back(index);
                    ans.emplace_back(j);
                }
            }
        }
        if (ans.size() == 0) return {0,0};
        return ans;
    }
};