//
// Created by 阳寜 on 2023/11/15.
//
#include<bits/stdc++.h>

using namespace std;

class Solution {
public:
    int maximizeSum(vector<int>& nums, int k) {
        int maxNum = INT_MIN;
        int numSize = nums.size();
        for (int i = 0; i < numSize; ++i) {
            maxNum = max(maxNum,nums[i]);
        }
        return (k * (k - 1))/2 + maxNum*k;
    }
};
int main() {
    return 0;
}
