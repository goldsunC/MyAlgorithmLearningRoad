//
// Created by 阳寜 on 2023/11/7.
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

/*
 * 层次遍历，就是用队列，BFS
 * 和普通的层次遍历输出不同，需要分别输出每一层的节点
 * */
class Solution {
public:
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> ret;
        if (!root) {
            return ret;
        }
        //队列
        queue<TreeNode*> q;
        //先把根节点放进队列
        q.push(root);
        while (!q.empty()) {
            //计算当前队列长度
            int currentLevelSize = q.size();
            ret.push_back(vector<int>());
            for (int i = 0; i < currentLevelSize; ++i) {
                auto node = q.front();
                q.pop();
                //ret.back()表示对ret中最后一个元素的引用，因为前边
                //在ret中push了一个新vector，所以引用是那个空vector
                ret.back().push_back(node->val);
                if (node->left) q.push(node->left);
                if (node->right) q.push(node->right);
            }
        }
        return ret;
    }
};
int main() {


    return 0;
}
