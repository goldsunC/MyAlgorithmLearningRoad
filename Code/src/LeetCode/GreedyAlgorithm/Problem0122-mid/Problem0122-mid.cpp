//
// Created by 阳寜 on 2023/10/24.
//
#include<bits/stdc++.h>

using namespace std;

//贪心策略。
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int ans = 0;
        int num = prices.size();
        for (int i = 1; i < n; ++i) {
            ans += max(0,prices[i] - prices[i-1]);
        }
        return ans;
    }
};

int main() {


    return 0;
}
