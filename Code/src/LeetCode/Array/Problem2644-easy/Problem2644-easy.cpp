//
// Created by 阳寜 on 2024/5/18.
//
#include<bits/stdc++.h>

/**
 *  Definition for singly-linked list.
*/
//struct ListNode {
//    int val;
//    ListNode *next;
//    ListNode(int x) : val(x), next(NULL) {}
//};

/**
 * Definition for a binary tree node.
*/
//struct TreeNode {
//int val;
//TreeNode *left;
//TreeNode *right;
//TreeNode() : val(0), left(nullptr), right(nullptr) {}
//TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
//TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
//}; 

typedef long long ll;
using namespace std;
class Solution {
public:
    int maxDivScore(vector<int>& nums, vector<int>& divisors) {
        pair<int,int> iAndScore = {-1,0};

        for (int i = 0; i < divisors.size(); ++i) {
            // iMax表示i的可整除性得分
            int iMax = 0;
            for (int j = 0; j < nums.size(); ++j) {
                if (nums[j] % divisors[i] == 0) iMax++;
            }
            if (iMax > iAndScore.first) {
                iAndScore.first = iMax;
                iAndScore.second = divisors[i];
            }
            if (iMax == iAndScore.first) {
                iAndScore.second = min(divisors[i],iAndScore.second);
            }
        }
        if (iAndScore.first == -1) return *max_element(divisors.begin(),divisors.end());
        return iAndScore.second;
    }
};