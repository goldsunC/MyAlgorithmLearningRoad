//
// Created by 阳寜 on 2024/5/12.
//
#include<bits/stdc++.h>

typedef long long ll;
using namespace std;
class Solution {
public:
    int findPermutationDifference(string s, string t) {
        unordered_map<char,vector<int>> map1;
        int ans = 0;
        for (int i = 0; i < s.size(); ++i) {
            map1[s[i]].emplace_back(i);
        }
        for (int i = 0; i < t.size(); ++i) {
            map1[t[i]].emplace_back(i);
        }
        for (auto ch : map1) {
            ans += abs(ch.second[0] - ch.second[1]);
        }
        return ans;
    }
};