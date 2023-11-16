//
// Created by 阳寜 on 2023/11/16.
//
#include<bits/stdc++.h>

using namespace std;

/* 这道题第一思路是遍历中间的j，然后从两头相向遍历或者从中间向两头遍历。
 * 按照如上思路的话，时间复杂度为O(n*n)，看数据好像过不了的样子
 * 但实际上，可以通过空间换时间，采用前后缀思路启发，
 * 用两个数组分别记录当前位置前后所有元素的最小值，这样在找最小元素时
 * 直接访问数组即可，完成两个数组的时间都是O(n)，最后遍历结果也是O(n)，
 * 总共3*O(n)，空间为2*O(n)
 *
 * 和238题很相似，238是维护当前位置前后的乘积数组。
 */
class Solution {
public:
    bool increasingTriplet(vector<int>& nums) {
        if (nums.size() <= 2) return false;
        vector<int> leftMin(nums.size());
        vector<int> rightMax(nums.size());
        leftMin[0] = INT_MAX;
        leftMin[1] = nums[0];
        rightMax[nums.size() - 2] = nums[nums.size() - 1];
        rightMax[nums.size() - 1] = INT_MIN;
        for (int i = 2; i < nums.size(); ++i) {
            leftMin[i] = min(leftMin[i - 1],nums[i - 1]);
        }
        for (int i = nums.size() - 3; i >= 0; --i) {
            rightMax[i] = max(rightMax[i + 1], nums[i + 1]);
        }
        for (int i = 1; i < nums.size() - 1; ++i) {
            if (nums[i] < rightMax[i] && nums[i] > leftMin[i])
                return true;
        }
        return false;
    }
};
int main() {
    vector<int> nums = {20,100,10,12,5,13};
    Solution solution;
    cout << solution.increasingTriplet(nums);
    return 0;
}
