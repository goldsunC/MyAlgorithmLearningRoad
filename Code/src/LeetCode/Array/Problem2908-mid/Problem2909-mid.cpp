//
// Created by 阳寜 on 2023/10/25.
//
#include<bits/stdc++.h>

using namespace std;
/*
 * 此题是P2908的升级版，加强点在于数据的规模变大了，2908用n方复杂度轻松AC，
 * 此题最好用O(n)复杂度。如下所示代码
 * */
class Solution {
public:
    int minimumSum(vector<int>& nums) {
        int minSum = 300000000;
        int nowSum;
        int pre [nums.size()];
        int suffix [nums.size()];
        pre[0] = nums[0];
        suffix[nums.size() - 1] = nums[nums.size() - 1];
        for (int i = 1; i < nums.size(); ++i) {
            pre[i] = min(pre[i-1] , nums[i]);
        }
        for (int i = nums.size()-2; i > -1; --i) {
            suffix[i] = min(suffix[i+1] , nums[i]);
        }
        for (int j = 1; j < nums.size() - 1; ++j) {
            if(pre[j-1] < nums[j] && suffix[j+1] < nums[j]) {
                nowSum = pre[j-1] + nums[j] + suffix[j+1];
                if (nowSum < minSum) minSum = nowSum;
            }
        }
        return (minSum==300000000)?-1:minSum;
    }
};

int main() {
    Solution solution;
    vector<int> nums = {5,4,8,7,10,2};
    cout << solution.minimumSum(nums) <<endl;
    return 0;
}
