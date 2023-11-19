//
// Created by 阳寜 on 2023/11/19.
//
#include<bits/stdc++.h>

typedef long long ll;
using namespace std;
class Solution {
public:
    int findMinimumOperations(string s1, string s2, string s3) {
        int length = 0;
        int n = min(s3.size(),min(s1.size(),s2.size()));
        while (length < n) {
            if (s1[length] == s2[length] && s1[length] == s3[length]) {
                length++;
            }else {
                break;
            }
        }
        int ans = s1.size() + s2.size() + s3.size() - 3*length;
        return length == 0? -1 :ans;
    }
};
int main() {
    Solution solution;
    string s1 = "dac",s2 = "bac",s3 = "cac";
    cout << solution.findMinimumOperations(s1,s2,s3);
}