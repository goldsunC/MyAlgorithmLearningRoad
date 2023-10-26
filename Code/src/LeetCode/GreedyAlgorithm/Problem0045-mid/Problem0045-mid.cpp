//
// Created by 阳寜 on 2023/10/26.
//
#include<bits/stdc++.h>

using namespace std;

/*
 * 跳跃游戏2：题目0055要求判断是否能跳跃到最后，此题测试用例均能跳跃到最后，
 * 需要求得最小条约次数
 *
 * 思路：经过用笔比比划划，一个思路是参考0055，每次维护一个可到达的最远距离，
 * 而可以经某结点到达最远距离的那个结点，便是跳跃最少次数必须经过的结点。
 * 具体实现不好做，参考了力扣题解，从左到右遍历数组，到达边界时，更新边界。并
 * 将条约次数增加1。边界即当前能够到达的最大下标位置。
 * 由此，记录必须经过的节点数即可得到答案。
 * */

class Solution {
public:
    int jump(vector<int>& nums) {
        //maxPos:当前能到达的最大位置，end:上次跳跃可达范围的右边界
        int maxPos = 0,n = nums.size(),end=0, ans = 0;
        for (int i = 0; i < n - 1; ++i) {
//            if (maxPos >= i) { 可以注释掉，因为题目给定一定能跳跃到最后
                maxPos = max(maxPos, i+nums[i]);
                //到达上次跳跃能到达的右边界,这里是精髓
                if (i == end) {
                    end = maxPos;
                    ++ans;
                }
//            }
        }
        return ans;
    }
};

int main() {
    Solution solution;
    vector<int> nums = {7,0,9,6,9,6,1,7,9,0,1,2,9,0,3};
    cout << solution.jump(nums);
    return 0;
}
