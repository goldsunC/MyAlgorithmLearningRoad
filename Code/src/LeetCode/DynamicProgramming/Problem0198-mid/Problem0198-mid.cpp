//
// Created by 阳寜 on 2023/11/1.
//
#include<bits/stdc++.h>

using namespace std;
class Solution {
public:
    int rob(vector<int>& nums) {
        if (nums.size() == 0) return 0;
        if (nums.size() == 1) return nums[0];
        if (nums.size() == 2) return max(nums[0],nums[1]);
        vector<int> opt(nums.size());
        opt[0] = nums[0];
        opt[1] = max(nums[0],nums[1]);
        for (int i = 2; i < nums.size(); ++i) {
            opt[i] = max(opt[i - 2] + nums[i], opt[i - 1]);
        }
        return opt[opt.size() - 1];
    }
};
int main() {
    return 0;
}
