//
// Created by 阳寜 on 2023/11/16.
//
#include<bits/stdc++.h>

using namespace std;
class Solution {
public:
    int maxOperations(vector<int>& nums, int k) {
        sort(nums.begin(),nums.end());
        int n = nums.size();
        int left = 0;
        int right = n - 1;
        int maxOp = 0;
        while (left < right) {
            int sum = nums[left] + nums[right];
            if (sum < k) {
                left++;
            } else if (sum > k) {
                right--;
            }
            else {
                maxOp++;
                left++;
                right--;
            }
        }
        return maxOp;
    }
};

int main() {
    return 0;
}
