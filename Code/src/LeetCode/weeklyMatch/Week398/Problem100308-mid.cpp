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
    /*
     * 思路：前缀和。
     * 开辟一个数组:a[i] = 0 ,if nums[i] mod 2 != nums[i+1] mod 2
     *            a[i] = 1 ,if nums[i] mod 2 == nums[i+1] mod 2
     * 相邻两数的异或和的最低位取反，即为a[i]
     * */
    vector<bool> isArraySpecial(vector<int>& nums, vector<vector<int>>& queries) {
        vector<int> a(nums.size(),0);
        for (int i = 1; i < nums.size(); ++i) {
            a[i] = a[i-1] + ((nums[i] ^ nums[i-1] ^ 1) & 1);
        }
        vector<bool> ans(queries.size());
        for (int i = 0; i < queries.size(); ++i) {
            auto& q = queries[i];
            ans[i] = a[q[0]] == a[q[1]];
        }
        return ans;
    }
};