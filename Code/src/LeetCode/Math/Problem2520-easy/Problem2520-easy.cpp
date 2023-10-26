//
// Created by 阳寜 on 2023/10/26.
//
#include<bits/stdc++.h>

using namespace std;
/*
 * 给一个整数num，返回num中能整除num的数位的数目。
 * 如num = 1248， 输出4，因为1248可以被1，2，4，8都整除。
 * */
class Solution {
public:
    int countDigits(int num) {
        int ans = 0;
        string s = to_string(num);
        for(char ch : s) {
            if (num % (ch - '0') == 0) ans++;
        }
        return ans;
    }
};
int main() {
    int num = 1248;
    Solution solution;
    cout << solution.countDigits(num);
    return 0;
}
