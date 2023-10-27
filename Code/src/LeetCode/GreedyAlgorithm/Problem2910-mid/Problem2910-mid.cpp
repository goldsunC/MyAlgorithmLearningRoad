//
// Created by 阳寜 on 2023/10/26.
//
#include<bits/stdc++.h>

using namespace std;
/*
 * 思路：哈希存储各个元素的数量，键的数量为最优分组数，如果
 * 存在某些值的数量差大于1，则选择值的数量多的往下分。
 * 找到元素最少的，它决定了分组的上限。
 * */
class Solution {
public:
    int minGroupsForValidAssignment(vector<int>& nums) {
        unordered_map<int, int> hashMap;
        for (int i = 0; i < nums.size(); ++i) {
            hashMap[nums[i]]++;
        }
        return 0;
    }
};
int main() {
    Solution solution;
    vector<int> nums = {10,10,10,3,1,1};
    cout << solution.minGroupsForValidAssignment(nums);
    return 0;
}
