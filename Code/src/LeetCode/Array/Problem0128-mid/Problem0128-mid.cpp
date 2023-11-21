//
// Created by 阳寜 on 2023/11/21.
//
#include<bits/stdc++.h>

typedef long long ll;
using namespace std;

//这道题官方时间复杂度和空间复杂度都是O(n)，但是感觉很离谱

class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int> num_set;
        //首先去重
        for (const int& num : nums) {
            num_set.insert(num);
        }
        //最大连续长度 set.count()函数时间复杂度为O(1)，为核心
        int longestStreak = 0;
        //对于每个元素，如果比它小的前一个数存在说明其可能是连续
        //序列的后部分，就跳过，如果不存在，则从它的位置向后查询，
        //因为此时它只可能是连续序列的开头。
        for (const int& num : num_set) {
            if (!num_set.count(num - 1)) {
                int currentNum = num;
                int currentStreak = 1;

                while (num_set.count(currentNum + 1)) {
                    currentNum += 1;
                    currentStreak += 1;
                }

                longestStreak = max(longestStreak, currentStreak);
            }
        }

        return longestStreak;
    }
};