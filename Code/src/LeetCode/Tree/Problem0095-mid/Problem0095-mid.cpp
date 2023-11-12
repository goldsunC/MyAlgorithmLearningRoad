//
// Created by 阳寜 on 2023/11/12.
//
#include<bits/stdc++.h>

using namespace std;
class TreeNode {
public:
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(){}
    TreeNode(int x){ this->val = x; }
    TreeNode(int x, TreeNode *left, TreeNode *right) {
        this->val = x;
        this->left = left;
        this->right = right;
    }
};
class Solution {
public:
    vector<TreeNode*> generateTrees(int n) {

    }
};
int main() {
    return 0;
}
