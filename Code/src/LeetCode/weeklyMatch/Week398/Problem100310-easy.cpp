//
// Created by 阳寜 on 2024/5/19.
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
    bool isArraySpecial(vector<int>& nums) {
        if (nums.size() == 1) return true;
        bool odd = true;
        if (nums[0] % 2 == 0) odd = false;
        for (int i = 1; i < nums.size(); ++i) {
            bool signOdd;
            if (nums[i] % 2 == 0) {
                signOdd = false;
            }else {
                signOdd = true;
            }
            if (signOdd == odd) {
                return false;
            }else {
                odd = !odd;
            }
        }
        return true;
    }
};