//
// Created by 阳寜 on 2023/10/29.
//
#include<bits/stdc++.h>

using namespace std;
class Solution {
public:
    long long minSum(vector<int>& nums1, vector<int>& nums2) {
        long long sum1 = 0, sum2 = 0;
        int sum1zero = 0, sum2zero = 0;
        for(int i : nums1) {
            sum1 += max(i,1);
            if (i == 0) {
                sum1zero++;
            }
        }
        for (int i : nums2) {
            sum2 += max(i,1);
            if (i == 0) {
                sum2zero++;
            }
        }
        if (sum1zero && sum2zero) return max(sum1,sum2);
        if (sum1zero == 0 && sum2zero != 0) return sum1 >= sum2? sum1 : -1;
        if (sum1zero != 0 && sum2zero == 0) return sum2 >= sum1? sum2 : -1;
        return sum1 == sum2 ? sum1 : -1;
    }
};
int main() {
    vector<int> nums1 = {2,0,2,0};
    vector<int> nums2 = {1,4};
    Solution solution;
    cout << solution.minSum(nums1,nums2);
    return 0;
}
