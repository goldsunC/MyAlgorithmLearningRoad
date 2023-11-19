//
// Created by 阳寜 on 2023/11/19.
//
#include<bits/stdc++.h>

typedef long long ll;
using namespace std;
class Solution {
public:
    int maximumXorProduct(long long a, long long b, int n) {
        int mod = 1e9 + 7;
        string a1 = to_string(a);
        string b1 = to_string(b);
        char ans[50] = {'0'};
        for (int i = 49; i > 50 - n - 1; --i) {
            ans[i] = a1 | b1;
        }
        string aaa = (string) ans;
        return stoi(aaa) % mod;
    }
};
int main() {
    Solution solution;
    cout << solution.maximumXorProduct(12,5,4);
}