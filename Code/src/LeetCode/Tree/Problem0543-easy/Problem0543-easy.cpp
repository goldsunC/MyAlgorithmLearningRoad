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
struct TreeNode {
int val;
TreeNode *left;
TreeNode *right;
TreeNode() : val(0), left(nullptr), right(nullptr) {}
TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

typedef long long ll;
using namespace std;

class Solution {
    /*
     * depth()计算某节点的深度。
     * */
    int ans;
    int depth(TreeNode* root) {
        if (root == NULL) {
            return 0;
        }
        int L = depth(root->left);
        int R = depth(root->right);
        ans = max(ans, L + R + 1);
        return max(L,R) + 1;
    }
public:
    int diameterOfBinaryTree(TreeNode* root) {
        ans = 1;
        depth(root);
        //为什么返回ans - 1？因为L和R都包括了该子树的根节点
        return ans - 1;
    }
};