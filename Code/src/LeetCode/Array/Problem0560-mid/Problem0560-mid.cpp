//
// Created by 阳寜 on 2023/11/9.
//
#include<bits/stdc++.h>

using namespace std;
// 超时了
class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        int ans = 0;
        int sum = 0;
        for (int i = 0; i < nums.size(); ++i) {
            for (int j = i; j >= 0; --j) {
                sum += nums[j];
                if (sum == k) {
                    ans++;
                }
            }
            sum = 0;
        }
        return ans;
    }
};
int main() {


    return 0;
}
