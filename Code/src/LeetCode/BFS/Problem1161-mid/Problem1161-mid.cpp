//
// Created by 阳寜 on 2023/11/16.
//
#include<bits/stdc++.h>

using namespace std;

// Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 };

class Solution {
public:
    int maxLevelSum(TreeNode* root) {
        if (!root) return 0;
        int ans = 0;
        int ansMaxSum = INT_MIN;
        int currentDepth = 0;
        queue<TreeNode *> q;
        q.push(root);
        while (!q.empty()) {
            int currentSize = q.size();
            int sum = 0;
            currentDepth++;
            for (int i = 0; i < currentSize; ++i) {
                TreeNode * top = q.front();
                sum += top->val;
                q.pop();
                if (top->left) q.push(top->left);
                if (top->right) q.push(top->right);
            }
            if (sum > ansMaxSum) {
                ansMaxSum = sum;
                ans = currentDepth;
            }
        }
        return ans;
    }
};
int main() {
    return 0;
}
