//
// Created by 阳寜 on 2023/11/2.
//
#include<bits/stdc++.h>
/*
 * 思路，一开始是打算排好序，固定j然后左右找i和k，结果发现不好处理有两数
 * 相等的情况。。。还没相出解决办法，转固定i了。
 * */
using namespace std;
class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> ans;
        sort(nums.begin(),nums.end());
        for (int i = 0; i < nums.size() - 2; ++i) {
            if (nums[i] > 0) return ans;
            if (i > 0 && nums[i] == nums[i-1]) continue;
            int j = i+1;
            int k = nums.size() - 1;
            while (j < k) {
                if (nums[i] + nums[j] + nums[k] > 0) {
                    k--;
                } else if (nums[i] + nums[j] + nums[k] < 0) {
                    j++;
                } else {
                    ans.insert(ans.end(),{nums[i],nums[j],nums[k]});
                    k--;
                    j++;
                    //去重
                    // 例如：[-4,1,1,1,2,3,3,3], i=0, left=1, right=5
                    while (j < k && nums[j] == nums[j-1])  j++;
                    while (j < k && nums[k] == nums[k+1])    k--;
                }
            }
        }
        return ans;
    }
};
int main() {
    vector<int> nums = {-1,0,1,2,-1,-4};
    Solution solution;
    solution.threeSum(nums);
    return 0;
}
