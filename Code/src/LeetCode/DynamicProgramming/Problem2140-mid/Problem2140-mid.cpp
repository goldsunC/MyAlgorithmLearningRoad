//
// Created by 阳寜 on 2023/11/14.
//
#include<bits/stdc++.h>

using namespace std;

class Solution {
public:
    long long mostPoints(vector<vector<int>>& questions) {
        if (questions.size() == 1) return questions[0][0];
        vector<long long> opt(questions.size(),0);
        vector<long long> pre(questions.size());
        pre[0] = 0;
        opt[0] = questions[0][0];
        int stop =min((int)questions.size() - 1,questions[0][1]);
        for (int i = 1; i <= stop; ++i) {
            opt[i] = max(opt[i - 1],(long long)questions[i][0]);
        }
        for (int i = questions.size() - 1; i > 0; --i) {
            for (int j = i - 1; j >= 0; --j) {
                if (j + questions[j][1] < i) {
                    pre[i] = j;
                    break;
                }
            }
        }
        for (int i = questions[0][1] + 1; i < questions.size(); ++i) {
            opt[i] = max(opt[pre[i]] + questions[i][0],opt[i-1]);
        }
        return opt[questions.size() - 1];
    }
};
int main() {
    vector<vector<int>> questions = {{12,46},{78,19},{63,15},{79,62},{13,10}};
    Solution solution;
    cout << solution.mostPoints(questions);
    return 0;
}
