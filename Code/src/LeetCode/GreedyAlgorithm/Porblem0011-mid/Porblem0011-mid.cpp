//
// Created by 阳寜 on 2023/10/24.
//
#include<bits/stdc++.h>

using namespace std;

class Solution {
public:
    int maxArea(vector<int>& height) {
        int n = height.size();
        int maxWater = 0;
        int left = 0;
        int right = n - 1;
        while (left < right) {
            int nowWater = min(height[left],height[right]) * (right - left);
            maxWater = max(maxWater,nowWater);
            height[left] < height[right] ? left++ : right--;
        }
        return maxWater;
    }
};

int main() {
    Solution solution;
    vector<int> height = {1,1};
    cout << solution.maxArea(height) << endl;
    return 0;
}
