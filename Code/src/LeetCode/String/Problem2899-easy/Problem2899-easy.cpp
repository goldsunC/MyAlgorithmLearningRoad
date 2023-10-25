//
// Created by 阳寜 on 2023/10/25.
//
#include<bits/stdc++.h>

using namespace std;

/*
 * 题目要求较长，官网查看
 * 注意：K表示到当前位置为止的 《连续》的 "prev"字符串数目，注意连续啊，
 * 每次不连续后要把k重置为0，做的时候没注意连续俩字，一直找bug，最后发现题目都是错的。
 * 看了答案不一样的地方才发现题读错了。害。
 * */
class Solution {
public:
    vector<int> lastVisitedIntegers(vector<string>& words) {
        int k = 0;
        vector<int> nums , ans;
        for(int i=0; i < words.size(); i++) {
            if (words[i] == "prev") {
                k++;
                if (k > nums.size()) {
                    ans.push_back(-1);
                }else {
                    ans.push_back(nums[nums.size() - k]);
                }
            }else {
                k = 0;
                nums.push_back(stoi(words[i]));
            }
        }
        return ans;
    }
};

int main() {
    Solution solution;
    vector<string> words = {"1","prev","2","prev","prev"};
    solution.lastVisitedIntegers(words);
    return 0;
}
