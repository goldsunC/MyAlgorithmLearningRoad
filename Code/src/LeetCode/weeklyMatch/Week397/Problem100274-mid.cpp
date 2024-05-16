//
// Created by 阳寜 on 2024/5/12.
//
#include<bits/stdc++.h>

typedef long long ll;
using namespace std;
class Solution {
public:
    int maximumEnergy(vector<int>& energy, int k) {
        vector<vector<int>> ans(k);
        int n = energy.size();
        for (int i = 0; i < k; ++i) {
            int current = i;
            ans[i].emplace_back(energy[i]);
            while (current + k < n) {
                ans[i].emplace_back(energy[current + k]);
                current += k;
            }
        }
        int answer = INT_MIN;
        for (auto a : ans) {
            answer = max(answer, maxEnergy(a));
        }
        return answer;
    }
    int maxEnergy(vector<int>& nums) {
        vector<int> opt(nums.size());
        opt[0] = nums[0];
        for (int i = 1; i < nums.size(); ++i) {
            opt[i] = max(opt[i - 1] + nums[i], nums[i]);
        }
        return opt[nums.size() - 1];
    }
};
int main() {
    Solution solution;
    vector<int> energy = {5,2,-10,-5,1};
    solution.maximumEnergy(energy,3);
}