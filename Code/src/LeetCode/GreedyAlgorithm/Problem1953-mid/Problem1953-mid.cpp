//
// Created by 阳寜 on 2024/5/16.
//
#include<bits/stdc++.h>

typedef long long ll;
using namespace std;
class Solution {
public:
    long long numberOfWeeks(vector<int>& milestones) {
        /*
         * 计算数组最大值 maxTask：最多阶段任务的项目
         * 计算除最大值之外的所有数之和 otherTasks：剩余的阶段任务数目
         * 如果maxTask > otherTasks，则otherTasks都可以完成，且使用交替方法maxTask最多完成otherTasks + 1
         * 如果maxTask <= otherTasks,则所有任务都可完成
         * */
        ll maxTask = *max_element(milestones.begin(),milestones.end());
        ll otherTasks = accumulate(milestones.begin(),milestones.end(),0ll) - maxTask;
        if (maxTask <= otherTasks) return (ll)accumulate(milestones.begin(),milestones.end(),0ll);
        return otherTasks * 2 + 1;
    }
};