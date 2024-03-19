//
// Created by 阳寜 on 2023/11/25.
//
#include<bits/stdc++.h>

typedef long long ll;
using namespace std;
class Solution {
public:
    vector<int> findWordsContaining(vector<string>& words, char x) {
        vector<int> ans;
        for (int i = 0; i < words.size(); ++i) {
            for(char ch : words[i]) {
                if (ch == x) {
                    ans.push_back(i);
                    break;
                }
            }
        }
        return ans;
    }
};
int main() {
    vector<string> words = {"leet","code"};
    Solution solution;
    for (auto i : solution.findWordsContaining(words,'e')) {
        cout << i;
    }
}