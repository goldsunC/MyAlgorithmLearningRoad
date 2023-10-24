//
// Created by 阳寜 on 2023/10/24.
//
#include<bits/stdc++.h>

using namespace std;

class Solution {
public:
    int maxArea(vector<int>& height) {
        int i = 0;
        int j = height.size() - 1;
        int water = 0;
        int nowWater;
        if (height.size() <= 1) return 0;
        while (i < j) {
            nowWater = (j-i) * min(height[i], height[j]);
            if (nowWater > water) water = nowWater;
            if (height[i] < height[j]) {
                i++;
            } else{
                j--;
            }
        }
        return water;
    }
};

int main() {
    Solution solution;
    vector<int> height = {1,1};
    cout << solution.maxArea(height) << endl;
    return 0;
}
