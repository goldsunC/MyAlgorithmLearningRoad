//
// Created by 阳寜 on 2023/11/13.
//
#include<bits/stdc++.h>

using namespace std;
struct TreeNode {
    int val;
    TreeNode * left;
    TreeNode * right;
    TreeNode():val(0),left(nullptr),right(nullptr) {}
    TreeNode(int x):val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode * left, TreeNode * right):val(x),left(left),right(right){}
};
class Solution {
public:
    // BFS实现
    vector<int> rightSideView(TreeNode* root) {
        vector<int> ans = {};
        if (!root) return ans;
        queue<TreeNode *> q;
        q.push(root);
        while (!q.empty()) {
            int currentSize = q.size();
            for (int i = 0; i < currentSize; ++i) {
                TreeNode* currentNode = q.front();
                if (i == currentSize - 1) ans.push_back(currentNode->val);
                if (currentNode->left) q.push(currentNode->left);
                if (currentNode->right) q.push(currentNode->right);
                q.pop();
            }
        }
        return ans;
    }
};
int main() {
    return 0;
}
