//
// Created by 阳寜 on 2023/11/2.
//
#include<bits/stdc++.h>

using namespace std;
class Solution {
public:
    int countPoints(string rings) {
        if (rings.size() < 6) return 0;
        int status[10][3] = {0};
        int ans = 0;
        for (int i = 0; i < rings.size() - 1; i += 2) {
            char a = rings[i];
            char b = rings[i+1];
            status[b - '0'][charToID(a)] = 1;
        }
        for (int i = 0; i < 10; ++i) {
            if (status[i][0] + status[i][1] + status[i][2] == 3) {
                ans ++;
            }
        }
        return ans;
    }
    int charToID(char ch) {
        if (ch == 'R') return 0;
        if (ch == 'G') return 1;
        return 2;
    }
};
int main() {
    string str = "B0B6G0R6R0R6G9";
    Solution solution;
    cout << solution.countPoints(str);
    return 0;
}
