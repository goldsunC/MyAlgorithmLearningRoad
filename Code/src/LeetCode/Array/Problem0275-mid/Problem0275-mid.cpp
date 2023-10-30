//
// Created by 阳寜 on 2023/10/30.
//
#include<bits/stdc++.h>

using namespace std;
class Solution {
public:
    int hIndex(vector<int>& citations) {
        int low = 0, high = citations.size() - 1;
        int mid = (low + high) / 2;
        while (low <= high) {
            if (citations[mid] >= citations.size() - mid) {
                high = mid - 1;
                mid = (low + high)/2;
            } else {
                low = mid + 1;
                mid = (low + high)/2;
            }
        }
        return citations.size() - low;
    }
};
int main() {
    Solution solution;
    vector<int> citations = {0,1};
    cout << solution.hIndex(citations);
    return 0;
}
