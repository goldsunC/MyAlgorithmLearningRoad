//
// Created by 阳寜 on 2023/11/7.
//
#include<bits/stdc++.h>

using namespace std;
class Solution {
public:
    vector<int> findDisappearedNumbers(vector<int>& nums) {
        int hash[100001] = {0};
        for (int i = 0; i < nums.size(); ++i) {
            hash[nums[i]]++;
        }
        vector<int> a;
        for (int i = 1; i < nums.size()+1; ++i) {
            if (hash[i] == 0 ) {
                a.push_back(i);
            }
        }
        return a;
    }
};
int main() {


    return 0;
}
