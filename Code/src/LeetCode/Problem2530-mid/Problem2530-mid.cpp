//
// Created by 阳寜 on 2023/10/18.
//
#include<bits/stdc++.h>

using namespace std;

class Solution {
public:
    long long maxKelements(vector<int>& nums, int k) {
        priority_queue<int> q(nums.begin(), nums.end());
        long long ans = 0;
        for (int _ = 0; _ < k; ++_) {
            int x = q.top();
            q.pop();
            ans += x;
            q.push((x + 2) / 3);
        }
        return ans;
    }
};


int main() {
    cout << "hello world!" <<endl;
    return 0;
}
