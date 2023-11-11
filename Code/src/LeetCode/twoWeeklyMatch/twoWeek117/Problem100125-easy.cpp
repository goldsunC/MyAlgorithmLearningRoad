//
// Created by 阳寜 on 2023/11/11.
//
#include<bits/stdc++.h>

using namespace std;
class Solution {
public:
    int distributeCandies(int n, int limit) {
        int ans = 0;
        int iminnum = max(0,n - limit*2);
        int imaxnum = min(limit,n);
//        for (int i = iminnum; i <= imaxnum; ++i) {
//            int shengyu = n-i;
//            int minnum = max(shengyu - limit,0);
//            int maxnum = min(limit,shengyu);
//            for (int j = minnum; j <= maxnum; ++j) {
//                ans++;
//            }
//        }
        int maxshengyu = n - iminnum;
        int minshengyu = n - imaxnum;
//        int jminnum = max(minshengyu - limit,0);
//        int jmaxnum = min(limit,maxshengyu);
        int a = max(limit,maxshengyu);
        int b = max(minshengyu,0);
        for (int i = b; i <= a+1; ++i) {
            ans += i;
        }
        return ans;
    }
};

int main() {
    Solution solution;
    cout << solution.distributeCandies(5,2);
    return 0;
}
