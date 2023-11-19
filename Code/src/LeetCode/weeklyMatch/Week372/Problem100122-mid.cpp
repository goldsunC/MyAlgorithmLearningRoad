//
// Created by 阳寜 on 2023/11/19.
//
#include<bits/stdc++.h>

typedef long long ll;
using namespace std;
class Solution {
public:
    long long minimumSteps(string s) {
        ll ans = 0;
        int n = s.size();
        int left = 0,right = 1;
        while (right < n && left < n) {
            if (s[left] == '0') {
                left++;
                right = left + 1;
                continue;
            }else {
                if (s[right] == '0') {
                    s[left] = '0';
                    s[right] = '1';
                    left++;
                    right++;
                    ans += right - left;
                }else {
                    right++;
                }
            }
        }
        return ans;
    }
};
int main() {
    Solution solution;
    cout << solution.minimumSteps("101");
}