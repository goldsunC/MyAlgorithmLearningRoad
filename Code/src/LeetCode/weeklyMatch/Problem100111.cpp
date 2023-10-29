//
// Created by 阳寜 on 2023/10/29.
//
#include<bits/stdc++.h>

using namespace std;

class Solution {
public:
    int findKOr(vector<int>& nums, int k) {
        int arr[31] = {0};
        int ans = 0;
        for (int i : nums) {
            for (int j = 0; j < 31; ++j) {
                if (i == 0) break;
                if (i & 0x1 == 1){
                    arr[j]++;
                    i = i >> 1;
                } else{
                    i = i >> 1;
                }
            }
        }
        for(int i = 0; i < 31 ; i++) {
            if (arr[i] >= k) {
                ans += pow(2,i);
            }
        }
        return ans;
    }
};

int main() {
    vector<int> nums = {10,8,5,9,11,6,8};
    Solution solution;
    cout << solution.findKOr(nums,1);
    return 0;
}
