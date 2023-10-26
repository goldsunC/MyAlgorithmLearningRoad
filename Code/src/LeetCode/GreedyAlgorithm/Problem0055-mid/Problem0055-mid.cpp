//
// Created by 阳寜 on 2023/10/26.
//
#include<bits/stdc++.h>

using namespace std;
/*
 * 给一个非负整数数组，最初位于数组的第一个下标，数组中的每个元素代表你在该位置
 * 可以跳跃的最大长度。
 * 判断是否能够到达最后一个下标，如果可以返回ture，否则返回false
 * */

/*
 * 思路：如果暴力解，可能最多需要O(a0* ... *an)，不现实
 * 初始思路：能否可以从尾部开始算，查找是否有一个元素a(n-1)直接能跳到最后，再查找是否有一个
 * 元素a(n-2)能跳到a(n-1)，最后一个到a0。时间复杂度为O(n^2),显然n^2并不容易达到，
 * 实际是O(n*需要跳跃的次数)
 * 太难实现了，难点在于数组中每个数是最大可跳位置。如果是唯一可跳位置则易实现。
 * */

/*
 * 正确思路：贪心(参考力扣官方题解)
 * 对于数组中任意一个数x，以它为基准，可以跳到它至x+nums[x]之间的所有距离
 * 其中x+nums[x]是可以到达的最远距离
 * 依次遍历数组中每一个数，如果这个数在之前可到达的最远距离之内，那么就可以通过
 * 一些跳跃来到达它，反之不行，一旦不行就输出false，如果能顺利遍历下去，
 * 且知道最远可到达的位置大于等于数组中最后一个位置，那就说明能够到达最后，返回true
 * */
class Solution {
public:
    bool canJump(vector<int>& nums) {
        if (nums.size() == 1) {
            if (nums[0] == 0 || nums[0] == 1) return true;
        }
        int end = nums.size() - 1;
        int maxDistance = 0;
        int nowMaxDistance;
        for (int i = 0; i < end; ++i) {
            if (i > maxDistance) return false;
            nowMaxDistance = i + nums[i];
            if (nowMaxDistance > maxDistance) maxDistance = nowMaxDistance;
            //可精简：maxDistance = max(nowMaxDistance,maxDistance)
            if (maxDistance >= end) return true;
        }
        return false;
    }
};

int main() {
    Solution solution;
    vector<int> nums = {2,0};
    cout << solution.canJump(nums);
    return 0;
}
