//
// Created by 阳寜 on 2023/11/2.
//
#include<bits/stdc++.h>

using namespace std;
class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        int maxnum = INT_MAX;
        int minnum = INT_MAX;
        for (int i = 0; i < nums.size()-2; ++i) {
            int j = i+1;
            int k = nums.size() - 1;
            while (j < k) {
                if(nums[i] + nums[j] + nums[k] == target) {
                    return target;
                } else if (nums[i]+nums[j]+nums[k]<target) {
                    minnum = min(minnum,target - nums[i]-nums[j]-nums[k]);
                    j++;
                }else {
                    maxnum = min(maxnum,nums[i]+nums[j]+nums[k] - target);
                    k--;
                }
            }
        }
        return (maxnum < minnum) ?(target+maxnum):(target-minnum);
    }
};
int main() {
    Solution solution;
    vector<int> nums = {-1000,-1000,1000,1000};
    cout << solution.threeSumClosest(nums,1000);
    return 0;
}
