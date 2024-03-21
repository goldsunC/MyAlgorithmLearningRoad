//
// Created by 阳寜 on 2024/3/20.
//
#include<bits/stdc++.h>

typedef long long ll;
using namespace std;
/*
 * 思路，双指针滑动窗口＋哈希表
 * 首先将p字符串中每个字母存储到哈希表中，键为字母，值为每个字母出现的次数
 * 左指针负责定位当前主串的位置，然后右指针从左指针开始向右遍历，最大长度为p的长度，
 * 每遍历一个位置，对应字符的哈希表值减一
 * 如果值一直不为0，那么到遍历到p的长度，返回左指针位置，左指针＋1
 * 如果值为0，则左指针向右一格，原位置的字符哈希表值＋1，然后继续校验原右指针对应值，
 * 直到该值不为0。
 * */

/*
 * 力扣直接通过，但是时间2122ms，击败5%，有很大优化空间。
 * */
class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        unordered_map<char, int> hashMap = {};
        for (char ch : p) {
            ++hashMap[ch];
        }
        unordered_map<char, int> useMap = hashMap;
        vector<int> ans = {};

        int leftPoint = 0, rightPoint = 0;
        int maxPos = s.size() - p.size();
        while (leftPoint <= maxPos) {
            //如果右指针字符值不为0且到达最大长度，则添加左指针到答案且左指针右移。
            if (rightPoint - leftPoint == p.size()) {
                ans.emplace_back(leftPoint);
                useMap[s[leftPoint]]++;
                ++leftPoint;
                continue;
            }
            //如果该字符不在p中出现，那么直接初始化左右指针到左指针的原来位置
            if (hashMap.count(s[rightPoint]) == 0) {
                ++leftPoint;
                rightPoint = leftPoint;
                useMap = hashMap;
                continue;
            }
            //如果右指针字符值为0，则左指针右移且对应字符值＋1
            if (useMap[s[rightPoint]] == 0) {
                ++useMap[s[leftPoint]];
                ++leftPoint;
                continue;
            }
            //右指针没有到达最大长度，且字符值不为0
            --useMap[s[rightPoint]];
            ++rightPoint;
        }
        return ans;
    }
};
