//
// Created by 阳寜 on 2024/5/17.
//
#include<bits/stdc++.h>

typedef long long ll;
using namespace std;
class Solution {
public:
    int maxProfitAssignment(vector<int>& difficulty, vector<int>& profit, vector<int>& worker) {
        //先把任务的难度和利润进行配对
        vector<pair<int,int>> tasks;
        int size = difficulty.size();
        for (int i = 0; i < size; ++i) {
            tasks.emplace_back(profit[i],difficulty[i]);
        }
        //对每个任务的利润进行排序，同时对工人的能力进行排序
        sort(tasks.begin(),tasks.end());
        sort(worker.begin(),worker.end());
        int maxProfit = 0;
        //对每个工人进行遍历，从利润最高开始，找到第一个能做的任务
        for (int i : worker) {  //i是worker的能力
            for (int j = size - 1; j >= 0; --j) {   //遍历利润
                //如果能力大于等于该利润下的难度，则总利润增加
                if (i >= tasks[j].second) {
                    maxProfit += tasks[j].first;
                    break;
                }
            }
        }
        return maxProfit;
    }
};