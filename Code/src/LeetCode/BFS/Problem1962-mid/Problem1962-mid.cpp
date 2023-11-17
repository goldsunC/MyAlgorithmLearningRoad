//
// Created by 阳寜 on 2023/11/16.
//
#include<bits/stdc++.h>

/*
 * 好像陷入误区了，树的BFS可以左右结点入队，
 * 但是图的BFS不可以一直上下左右入队，会陷入重复访问已经访问过的地方
 * 那么怎么解决呢
 * */
typedef long long ll;
using namespace std;
class Solution {
public:
    int nearestExit(vector<vector<char>>& maze, vector<int>& entrance) {
        // m行n列
        int m = maze.size();
        int n = maze[0].size();
        // 上下左右四个相邻坐标对应的行列变化量
        vector<int> dx = {1, 0, -1, 0};
        vector<int> dy = {0, 1, 0, -1};
        // tuple ：元组 元组的三个位分别表示横纵坐标以及相对入口的距离
        // 即(x,y,distance)
        queue<tuple<int, int, int>> q;
        // 入口加入队列并修改为墙
        q.emplace(entrance[0], entrance[1], 0);
        maze[entrance[0]][entrance[1]] = '+';
        while (!q.empty()){
            auto [cx, cy, d] = q.front();
            q.pop();
            // 遍历四个方向相邻坐标
            for (int k = 0; k < 4; ++k){
                int nx = cx + dx[k];
                int ny = cy + dy[k];
                // 新坐标合法且不为墙
                if (nx >= 0 && nx < m && ny >= 0 && ny < n && maze[nx][ny] == '.'){
                    if (nx == 0 || nx == m - 1 || ny == 0 || ny == n - 1){
                        // 新坐标为出口，返回距离作为答案
                        return d + 1;
                    }
                    // 新坐标为空格子且不为出口，修改为墙并加入队列
                    maze[nx][ny] = '+';
                    q.emplace(nx, ny, d + 1);
                }
            }
        }
        // 不存在到出口的路径，返回 -1
        return -1;
    }
};

