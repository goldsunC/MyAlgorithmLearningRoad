//
// Created by 阳寜 on 2023/10/24.
//
#include<bits/stdc++.h>

using namespace std;
class Solution {
public:
    int minimumSum(vector<int>& nums) {
        int minSum = 151;
        int nowSum;
        for (int j = 1; j < nums.size() - 1; ++j) {
            int preMinNum = 51;
            int sufMinNum = 51;
            int i = 0;
            int k = nums.size() -1;
            while (i < j) {
                if (nums[i] < preMinNum) {
                    preMinNum = nums[i];
                }
                ++i;
            }
            while (k > j) {
                if (nums[k] < sufMinNum) {
                    sufMinNum = nums[k];
                }
                --k;
            }
            if (preMinNum < nums[j] && sufMinNum < nums[j]) {
                nowSum = preMinNum + nums[j] + sufMinNum;
                if (nowSum < minSum) minSum = nowSum;
            }
        }
        return (minSum == 151)?-1:minSum;
    }
};
int main() {
    Solution solution;
    vector<int> nums = {49,50,48};
    cout << solution.minimumSum(nums) <<endl;
    return 0;
}
