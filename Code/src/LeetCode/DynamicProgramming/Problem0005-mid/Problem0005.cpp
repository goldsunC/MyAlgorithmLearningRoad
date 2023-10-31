//
// Created by 阳寜 on 2023/10/31.
//
#include<bits/stdc++.h>

using namespace std;
class Solution {
public:
    string longestPalindrome(string s) {
        int n = s.size();
        if (n < 2) {
            return s;
        }
        int maxLen = 1;
        int begin = 0;
        // dp[i][j] 表示 s[i...j]是否是回文串
        vector<vector<int>> dp(n,vector<int>(n));
        // 初始化：所有长度为1的字串都是回文串
        for (int i = 0; i < n; ++i) {
            dp[i][i] = true;
        }
        // 递推开始
        // 先枚举字串长度
        for (int L = 2; L <= n; ++L) {
            //枚举左边界，左边界的上限设置可以宽松一些
            for (int i = 0; i < n; ++i) {
                //由L和i可以确定右边界， 即j - i + 1 = L得
                int j = L + i -1;
                //如果右边界越界，就可以退出当前循环
                if (j >= n) {
                    break;
                }
                if (s[i] != s[j]) {
                    dp[i][j] = false;
                } else {
                    if (j - i < 3) {
                        dp[i][j] = true;
                    } else {
                        dp[i][j] = dp[i + 1][j - 1];
                    }
                }
                // 只要 dp[i][L] == true 成立，就表示字串
                // s[i...L]是回文串，此时记录回文串长度和起始位置
                if (dp[i][j] && j - i + 1 > maxLen) {
                    maxLen = j - i + 1;
                    begin = i;
                }
            }
        }
        return s.substr(begin,maxLen);
    }
};
int main() {


    return 0;
}
