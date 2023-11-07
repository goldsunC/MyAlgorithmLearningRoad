//
// Created by 阳寜 on 2023/11/7.
//
#include<bits/stdc++.h>

/*
 * 此题要求时间复杂度O(n),空间复杂度O(1),
 * 正常思路先排序再遍历，时间O(nlogn),空间O(nlogn),不行
 * 思路二哈希表，统计各数出现次数，时间复杂度O(n),空间复杂度O(n),不行
 * */

class Solution {
public:
    vector<int> findDuplicates(vector<int>& nums) {
        int n = nums.size();
        for (int i = 0; i < n; ++i) {
            while (nums[i] != nums[nums[i] - 1]) {
                swap(nums[i], nums[nums[i] - 1]);
            }
        }
        vector<int> ans;
        for (int i = 0; i < n; ++i) {
            if (nums[i] - 1 != i) {
                ans.push_back(nums[i]);
            }
        }
        return ans;
    }
};

int main() {


    return 0;
}
