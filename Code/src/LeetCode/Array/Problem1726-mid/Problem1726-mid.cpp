//
// Created by 阳寜 on 2023/10/19.
//
#include<bits/stdc++.h>

using namespace std;

class Solution {
public:
    int tupleSameProduct(vector<int>& nums) {
        int n = nums.size();
        int ans = 0;
        unordered_map<int, int> cnt;
        for (int i = 0; i < n; i++) {
            for(int j = i + 1; j < n; j++) {
                cnt[nums[i] * nums[j]]++;
            }
        }
        for (auto &[k, v] : cnt) {
            ans += v * (v - 1) * 4;
        }
        return ans;
    }
};

int main() {
    Solution solution;
    vector<int> nums = {2,3,4,6};
    int res = solution.tupleSameProduct(nums);
    cout << res <<endl;
    return 0;
}
