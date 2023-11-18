//
// Created by 阳寜 on 2023/11/17.
//
#include<bits/stdc++.h>

typedef long long ll;
using namespace std;

//todo:超时
class Solution {
public:
    int numSubarrayProductLessThanK(vector<int>& nums, int k) {
        int ans = 0;
        for (int i = 0; i < nums.size(); ++i) {
            int dot = 1;
            for (int j = i; j < nums.size(); ++j) {
                dot *= nums[j];
                if (dot < k) {
                    ans++;
                }else{
                    dot = 1;
                    break;
                }
            }
        }
        return ans;
    }
};
int main() {
    Solution solution;
    vector<int> nums = {10,5,2,6};
    cout << solution.numSubarrayProductLessThanK(nums,100);
}