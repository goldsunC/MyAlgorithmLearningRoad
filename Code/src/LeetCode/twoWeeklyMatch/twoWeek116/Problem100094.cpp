//
// Created by 阳寜 on 2023/10/28.
//
#include<bits/stdc++.h>

using namespace std;

class Solution {
public:
    int sumCounts(vector<int>& nums) {
        int mod = 1e9 + 7;
        long long ans = 0;
        set<int> set;
        vector<int> sub;
        for (int k = 1; k < nums.size() + 1; ++k) {
            for (int i = 0,j = i + k;j < nums.size()+1; ++i,++j) {
                for (int l = i; l < j; ++l) {
                    set.insert(nums[l]);
                }
                cout << set.size() * set.size() << endl;
                ans += set.size() * set.size();
                set.clear();
            }
        }
        return ans%mod;
    }
};

int main() {
    vector<int> nums = {1,2,1};
    Solution solution;
    cout << solution.sumCounts(nums);
    return 0;
}
