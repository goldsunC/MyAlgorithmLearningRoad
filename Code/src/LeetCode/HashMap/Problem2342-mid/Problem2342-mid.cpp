//
// Created by 阳寜 on 2023/11/18.
//
#include<bits/stdc++.h>

typedef long long ll;
using namespace std;
class Solution {
public:
    int maximumSum(vector<int>& nums) {
        unordered_map<int,priority_queue<int>> map;
        for (int num : nums) {
            map[bitSum(num)].push(num);
        }
        int maxNum = -1;
        for (auto i : map) {
            if (i.second.size() < 2) continue;
            int curMaxNum = i.second.top();
            i.second.pop();
            curMaxNum += i.second.top();
            maxNum = max(maxNum,curMaxNum);
        }
        return maxNum;
    }
    int bitSum(int num) {
        int sum = 0;
        while (num != 0) {
            sum += num % 10;
            num /= 10;
        }
        return sum;
    }
};
int main() {
    Solution solution;
    cout << solution.bitSum(4355);
}