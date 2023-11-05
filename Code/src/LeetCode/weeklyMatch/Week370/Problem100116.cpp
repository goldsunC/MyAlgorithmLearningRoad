//
// Created by 阳寜 on 2023/11/5.
//
#include<bits/stdc++.h>

using namespace std;
class Solution {
public:
    int findChampion(int n, vector<vector<int>>& edges) {
        set<int> s;
        for (int i = 0; i < n; ++i) {
            s.insert(i);
        }
        for (int i = 0; i < edges.size(); ++i) {
            s.erase(edges[i][1]);
        }
        if (s.size() != 1) {
            return -1;
        }
        set<int>::iterator it;
        for(it = s.begin();;) {
            return *it;
        }
    }
};
int main() {
    int n = 3;
    vector<vector<int>> edges = {{0,1},{1,2}};
    Solution solution;
    cout << solution.findChampion(n,edges);
    return 0;
}
