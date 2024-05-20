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
    long long sumDigitDifferences(vector<int>& nums) {
        ll length;
        string str = to_string(nums[0]);
        length = str.size();
        ll num = 0;
        for (ll i = 0; i < length; ++i) {
            unordered_set<char> unorderedSet = {};
            for (ll j = 0; j < nums.size(); ++j) {
                unorderedSet.insert(to_string(nums[j])[i]);
            }
            if (unorderedSet.size() != 1) {
                num += unorderedSet.size();
            }
        }
        return num;
    }
};