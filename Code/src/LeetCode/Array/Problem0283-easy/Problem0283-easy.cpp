//
// Created by 阳寜 on 2023/11/4.
//
#include<bits/stdc++.h>

using namespace std;
class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int n = nums.size(), left = 0, right = 0;
        while (right < n) {
            if (nums[right]) {
                swap(nums[left], nums[right]);
                left++;
            }
            right++;
        }
    }
};
int main() {


    return 0;
}
