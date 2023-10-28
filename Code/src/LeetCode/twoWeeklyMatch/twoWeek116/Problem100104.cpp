//
// Created by 阳寜 on 2023/10/28.
//
#include<bits/stdc++.h>

using namespace std;
class Solution {
public:
    int minChanges(string s) {
        int ans = 0;
        for (int i = 0; i < s.length(); i = i+2) {
            if (s[i] != s[i+1]) {
                ans += 1;
            }
        }
        return ans;
    }
};
int main() {
    string s = "0000";
    Solution solution;
    cout << solution.minChanges(s);
    return 0;
}
