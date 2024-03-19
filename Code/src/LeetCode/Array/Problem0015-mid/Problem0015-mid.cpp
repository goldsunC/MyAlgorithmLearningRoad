//
// Created by 阳寜 on 2024/3/19.
//
#include<bits/stdc++.h>

typedef long long ll;
using namespace std;

/*
 * 思路：首先将原始数组进行排序，这样可以遍历整个数组，
 * 遍历的数作为基点，然后用双指针分别指向基点的下一个数和数组的最后一个数。
 * 此时计算三数之和，根据结果大小选择移动两个指针的的其中一个，直至双指针交汇。
 * 这样把原本需要的n*n*n复杂度变为了n*n复杂度。
 * */
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
                    while (j < k && nums[j] == nums[j-1])  j++;
                    while (j < k && nums[k] == nums[k+1])    k--;
                }
            }
        }
        return ans;
    }
};