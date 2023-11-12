//
// Created by 阳寜 on 2023/11/12.
//
#include<bits/stdc++.h>

using namespace std;
class Solution {
public:
    int maximumStrongPairXor(vector<int>& nums) {
        vector<vector<int>> pairs;
        int res = 0;
        if (nums.size() == 1) return 0;
        set<int> numss;
        vector<int> numsss;
        for (int i = 0; i < nums.size(); ++i) {
            numss.insert(nums[i]);
        }
        for(auto i : numss) {
            numsss.push_back(i);
        }
        for(int i = 0; i < numsss.size();++i) {
            for (int j = i; j < numsss.size(); ++j) {
                if (abs(numsss[i] - numsss[j]) <= min(numsss[i],numsss[j])) {
                    pairs.push_back({numsss[i],numsss[j]});
                }
            }
        }
        for (int i = 0; i < pairs.size(); ++i) {
            res = max(res,pairs[i][0] ^ pairs[i][1]);
        }
        return res;
    }
};
int main() {
    vector<int> nums = {10,100};
    Solution solution;
    cout << solution.maximumStrongPairXor(nums);
    return 0;
}
