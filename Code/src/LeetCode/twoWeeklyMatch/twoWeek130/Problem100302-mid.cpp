//
// Created by 阳寜 on 2024/5/11.
//
#include<bits/stdc++.h>

typedef long long ll;
using namespace std;
class Solution {
public:
    int maxPointsInsideSquare(vector<vector<int>>& points, string s) {
        unordered_map<char,int> map1;
        int banjing = INT_MAX;
        int ans = 0;
        for (int i = 0; i < s.size(); ++i) {
            if (map1[s[i]])
            {
                int a = max(abs(points[i][0]),abs(points[i][1]));
                if (a == map1[s[i]]) {
                    if (banjing >= a) {
                        banjing = a - 1;
                        continue;
                    }
                }
                int mina = min(a,map1[s[i]]);
                if (banjing >= mina) {
                    banjing = mina;
                }
            }else {
                map1[s[i]] = max(abs(points[i][0]),abs(points[i][1]));
            }
        }
        for (int i = 0; i < s.size(); ++i) {
            if (abs(points[i][0]) <= banjing && abs(points[i][i]) <= banjing) ++ans;
        }
        return ans;
    }
};
int main() {
    Solution solution;
    string s = "abdca";
    vector<vector<int>> points = {{2,2},{-1,-2},{-4,4},{-3,1},{3,-3}};
    cout << solution.maxPointsInsideSquare(points,s);
}