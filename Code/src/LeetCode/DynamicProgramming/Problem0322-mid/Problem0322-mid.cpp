//
// Created by 阳寜 on 2024/5/14.
//
#include<bits/stdc++.h>

typedef long long ll;
using namespace std;
class Solution {
public:
    /*设 F(i)为组成金额i所需最少的硬币数量。
    动态规划转移方程：F(i) = min (F(i-c1),F(i-c2),...,F(i-cn)) + 1
    */
    int coinChange(vector<int>& coins, int amount) {
        vector<int> opt(amount + 1,amount + 1);
        opt[0] = 0;
        for (int i = 1; i <= amount; ++i) {
            for (int j = 0; j < coins.size(); ++j) {
                if (coins[j] <= i) {
                    opt[i] = min(opt[i],opt[i - coins[j]] + 1);
                }
            }
        }
        return opt[amount] > amount ? -1 : opt[amount];
    }
};