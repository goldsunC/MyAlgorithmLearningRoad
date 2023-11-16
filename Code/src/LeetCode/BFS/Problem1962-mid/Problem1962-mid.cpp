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
        queue<pair<int, int>> q;
        int distance = 0;
        int currentSize = 1;
        q.push(pair<int,int> (entrance[0],entrance[1]));
        while (!q.empty()) {
            distance++;
            currentSize = q.size();
            for (int i = 0; i < currentSize; ++i) {
                // 取队头元素位置
                pair<int,int> pos = q.front();
                // 上面有路，入队
                if (maze[pos.first - 1][pos.second] == '.') {
                    q.push(pair<int,int>(pos.first-1,pos.second));
                    // 上面有路，且为边界,终止循环
                    if (pos.first - 1 == 0) {
                        q = queue<pair<int,int>>();
                        break;
                    }
                }
                // 下面有路，入队
                if (maze[pos.first + 1][pos.second] == '.') {
                    q.push(pair<int,int>(pos.first+1,pos.second));
                    // 下面有路，且为边界,终止循环
                    if (pos.first + 1 == 0) {
                        q = queue<pair<int,int>>();
                        break;
                    }
                }
                // 左面有路，入队
                if (maze[pos.first][pos.second - 1] == '.') {
                    q.push(pair<int,int>(pos.first,pos.second - 1));
                    // 左面有路，且为边界,终止循环
                    if (pos.second - 1 == 0) {
                        q = queue<pair<int,int>>();
                        break;
                    }
                }
                // 右面有路，入队
                if (maze[pos.first][pos.second + 1] == '.') {
                    q.push(pair<int,int>(pos.first,pos.second + 1));
                    // 右面有路，且为边界,终止循环
                    if (pos.second + 1 == 0) {
                        q = queue<pair<int,int>>();
                        break;
                    }
                }
                q.pop();
            }
        }
        return distance;
    }
};