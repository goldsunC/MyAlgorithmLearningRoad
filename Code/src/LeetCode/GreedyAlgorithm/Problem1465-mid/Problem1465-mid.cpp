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
        int maxHor = 0,maxVer = 0;
        for (int i = 1; i < horizontalCuts.size(); ++i) {
            maxHor = max(maxHor,horizontalCuts[i] - horizontalCuts[i-1]);
        }
        for (int i = 1; i < verticalCuts.size(); ++i) {
            maxVer = max(maxVer,verticalCuts[i] - verticalCuts[i-1]);
        }
        maxHor = max(maxHor,horizontalCuts[0]);
        maxHor = max(maxHor,h - horizontalCuts[horizontalCuts.size() - 1]);
        maxVer = max(maxVer,verticalCuts[0]);
        maxVer = max(maxVer,w - verticalCuts[verticalCuts.size() - 1]);
        long long hor = maxHor;
        long long ver = maxVer;
        return (hor*ver)%mod;
    }
};

int main() {
    vector<int> horizontalCuts = {3,1};
    vector<int> verticalCuts = {1};
    Solution solution;
    cout << solution.maxArea(5,4,horizontalCuts,verticalCuts);
    return 0;
}
