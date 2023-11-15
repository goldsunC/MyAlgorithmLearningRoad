//
// Created by 阳寜 on 2023/11/15.
//
#include<bits/stdc++.h>

using namespace std;
class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        vector<int> pre(nums.size());
        vector<int> ans(nums.size());
        pre[0] = 1;
        pre[1] = nums[0];
        for (int i = 2; i < nums.size(); ++i) {
            pre[i] = pre[i-1] * nums[i-1];
        }
        int after = 1;
        for (int i = nums.size() - 2; i > 0 ; --i) {
            after *= nums[i+1];
            ans[i] = pre[i] * after;
        }
        ans[0] = after * nums[1];
        ans[nums.size() - 1] = pre[nums.size()-1];
        return ans;
    }
};

int main() {
    return 0;
}
