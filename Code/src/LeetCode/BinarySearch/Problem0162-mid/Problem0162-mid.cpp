//
// Created by 阳寜 on 2023/11/16.
//
#include<bits/stdc++.h>

typedef long long ll;
using namespace std;

//实现O(n)很简单，但是O(logn)完全没思路
//看了题解，二分查找优化的方法是真6啊，多少沾点数学思路
//根本思路在于，对于每一个元素，它左右比它大的一方一定存在山峰。

class Solution {
public:
    int findPeakElement(vector<int>& nums) {
        int n = nums.size();
        if (n == 1) return 0;
        if (n == 2) return nums[0] > nums[1]?0:1;
        if (nums[0] > nums[1]) return 0;
        if (nums[n - 1] > nums[n - 2]) return n-1;
        int left = 0;
        int right = n - 1;
        int ansPos = 0;
        while (left < right) {
            int mid = (left + right) / 2;
            if (nums[mid - 1] < nums[mid] && nums[mid] > nums[mid + 1]) {
                ansPos = mid;
                break;
            }
            if (nums[mid - 1] > nums[mid]) {
                right = mid;
            }else {
                left = mid;
            }
        }
        return ansPos;
    }
};

int main() {
    vector<int> nums = {3,4,3,2,1};
    Solution solution;
    cout << solution.findPeakElement(nums);
}