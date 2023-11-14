//
// Created by 阳寜 on 2023/11/9.
//
#include<bits/stdc++.h>

using namespace std;
// 超时了
/*
class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        int ans = 0;
        for (int i = 0; i < nums.size(); ++i) {
            int sum = 0;
            for (int j = i; j < nums.size(); ++j) {
                sum += nums[j];
                if (sum == k) {
                    ans++;
                }
            }
        }
        return ans;
    }
};
 */
/*
 * 下面是官方题解，基本跟我写的一样啊，也超时了。。。
 * */
/*
class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        int count = 0;
        for (int start = 0; start < nums.size(); ++start) {
            int sum = 0;
            for (int end = start; end >= 0; --end) {
                sum += nums[end];
                if (sum == k) {
                    count++;
                }
            }
        }
        return count;
    }
};
*/
/*
 * 前缀和 + 哈希表优化，时间复杂度为O(n),空间复杂度也为O(n)
 * TODO:再理解理解
 * */
class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        unordered_map<int, int> mp;
        mp[0] = 1;
        int count = 0, pre = 0;
        for (auto& x:nums) {
            pre += x;
            if (mp.find(pre - k) != mp.end()) {
                count += mp[pre - k];
            }
            mp[pre]++;
        }
        return count;
    }
};

int main() {

    vector<int> nums = {1,-1,0};
    Solution solution;
    cout << solution.subarraySum(nums,0);
    return 0;
}
