//
// Created by 阳寜 on 2023/11/17.
//
#include<bits/stdc++.h>

typedef long long ll;
using namespace std;
class Solution {
public:
    int maxVowels(string s, int k) {
        int n = s.size();
        int curNum = 0;
        int maxNum = 0;
        int left = 1;
        int right = k;
        for (int i = 0; i < k; ++i) {
            if (isVowel(s[i])) {
                curNum++;
            }
        }
        maxNum = max(maxNum,curNum);
        for (; left < n - k + 1; ++left,++right) {
            if (isVowel(s[left-1])) {
                curNum--;
            }
            if (isVowel(s[right])) {
                curNum++;
            }
            maxNum = max(maxNum,curNum);
        }
        return maxNum;
    }
    bool isVowel(char ch) {
        if (ch == 'a' || ch == 'e' || ch == 'o' ||
            ch == 'i' || ch == 'u') return true;
        return false;
    }
};