//
// Created by 阳寜 on 2023/10/29.
//
#include<bits/stdc++.h>

using namespace std;
class Solution {
public:
    int hIndex(vector<int>& citations) {
        sort(citations.begin(),citations.end());
        int n = citations.size();
        int h = 0;
        for (int i = n - 1; i >=0; --i) {
            if (citations[i] < n-i) {
                return h;
            }
            h++;
        }
        return h;
    }
};
int main() {
    vector<int> citations = {1,3,1};
    Solution solution;
    cout << solution.hIndex(citations);
    return 0;
}
