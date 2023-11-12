//
// Created by 阳寜 on 2023/11/12.
//
#include<bits/stdc++.h>

using namespace std;
//Todo:debug
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
    vector<int> ans;
    void recoverTree(TreeNode* root) {
        vector<int> increaseOrder = midOrder(root);
        int xPos = -1;
        int xNum,yNum;
        for (int i = 0; i < increaseOrder.size() - 1; ++i) {
            if (increaseOrder[i] > increaseOrder[i+1]) {
                xPos = i;
                xNum = increaseOrder[i];
                yNum = increaseOrder[i+1];
                break;
            }
        }
        for (int i = xPos + 2; i < increaseOrder.size(); ++i) {
            if (increaseOrder[i] < increaseOrder[i-1]) {
                yNum = increaseOrder[i];
            }
        }
        reviseRoot(root,xNum,yNum);
    }
    vector<int> midOrder(TreeNode *root) {
        if (root->left) midOrder(root->left);
        ans.push_back(root->val);
        if (root->right) midOrder(root->right);
        return ans;
    }
    void reviseRoot(TreeNode *root, int x, int y) {
        if (root->val == x) root->val = y;
        if (root->val == y) root->val = x;
        if (root->left) reviseRoot(root->left,x,y);
        if (root->right) reviseRoot(root->right,x,y);
    }
};

int main() {
    return 0;
}
