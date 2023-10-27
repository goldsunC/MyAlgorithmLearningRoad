//
// Created by 阳寜 on 2023/10/27.
//
#include<bits/stdc++.h>

using namespace std;

/*
 * 讲道理，看到题完全没思路。
 * 题解思路，计算相邻切割位置之间的间隔。蛋糕面积 = 长*宽，找到最大的即可。
 * 开答案学到了Cpp的lambda函数用法
 * */

class Solution {
public:
    int maxArea(int h, int w, vector<int>& horizontalCuts, vector<int>& verticalCuts) {
        int mod = 1e9 + 7;
        sort(horizontalCuts.begin(), horizontalCuts.end());
        sort(verticalCuts.begin(), verticalCuts.end());
        auto calMax = [](vector<int> &arr, int boardr) -> int {
            int res = 0, pre = 0;
            for (int i : arr) {
                res = max(i - pre, res);
                pre = i;
            }
            return max(res, boardr - pre);
        };
        return (long long)calMax(horizontalCuts, h) * calMax(verticalCuts, w) % mod;
    }
};

int main() {


    return 0;
}
