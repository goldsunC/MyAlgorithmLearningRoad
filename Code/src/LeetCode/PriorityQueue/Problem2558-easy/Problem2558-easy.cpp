//
// Created by 阳寜 on 2023/10/28.
//
#include<bits/stdc++.h>

using namespace std;

/*
 * 思路：大根堆，很容易想到
 * */

class Solution {
public:
    long long pickGifts(vector<int>& gifts, int k) {
        priority_queue<int> q(gifts.begin(), gifts.end());
        while (k--) {
            int x = q.top();
            q.pop();
            q.push(int(sqrt(x)));
        }
        long long res = 0;
        while (q.size()) {
            res += q.top();
            q.pop();
        }
        return res;
    }
};


int main() {


    return 0;
}
