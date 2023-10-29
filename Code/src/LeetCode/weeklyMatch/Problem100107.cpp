//
// Created by 阳寜 on 2023/10/29.
//
#include<bits/stdc++.h>

using namespace std;
class Solution {
public:
    long long minIncrementOperations(vector<int>& nums, int k) {
        long long ans = 0;
        for (int i = 0; i <= nums.size()-3 && nums.size() - i >=3; i = i+3) {
            int maxNum = max(max(nums[i],nums[i+1]),nums[i+2]);
            if (maxNum < k) {
                ans += k-maxNum;
            }
        }
        if (nums.size()%3 == 1) {
            if(max(nums[nums.size()-2],nums[nums.size()-3]) > nums[nums.size()-4]) {
                return ans;
            }
            ans += k - nums[nums.size()-4];
        }
        if (nums.size()%3 == 2) {
            if (nums[nums.size()-3] > max(nums[nums.size()-4],nums[nums.size()-5])) {
                return ans;
            }
            if (nums[nums.size() - 1] > nums[nums.size() - 2]) {
                ans += k - nums[nums.size() - 1];
            }else {
                ans += k - nums[nums.size() - 2];
            }
        }
        return ans;
    }
};
int main() {
    vector<int> nums = {7,7,2,7};
    Solution solution;
    cout << solution.minIncrementOperations(nums,9);
    return 0;
}
