//
// Created by 阳寜 on 2023/11/12.
//
#include<bits/stdc++.h>

using namespace std;
class Solution {
public:
    long long maxSpending(vector<vector<int>>& values) {
        long long res = 0;
        priority_queue<long long> priorityQueue;
        for (int i = 0; i < values.size(); ++i) {
            for (int j = 0; j < values[0].size(); ++j) {
                priorityQueue.push(values[i][j]);
            }
        }
        for (int i = values.size() * values[0].size(); i >= 1; --i) {
            res += priorityQueue.top() * i;
            priorityQueue.pop();
        }
        return res;
    }
};
int main() {
    vector<vector<int>> values = {{8,5,2},{6,4,1},{9,7,3}};
    Solution solution;
    cout << solution.maxSpending(values);
    return 0;
}
