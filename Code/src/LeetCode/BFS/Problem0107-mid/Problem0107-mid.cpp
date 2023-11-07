//
// Created by 阳寜 on 2023/11/7.
//
#include<bits/stdc++.h>

using namespace std;

//Definition for a binary tree node.
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
    vector<vector<int>> levelOrderBottom(TreeNode* root) {
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
            ret.insert(ret.begin(),vector<int>());
            for (int i = 0; i < currentLevelSize; ++i) {
                auto node = q.front();
                q.pop();
                //ret.back()表示对ret中最后一个元素的引用，因为前边
                //在ret中push了一个新vector，所以引用是那个空vector
                ret[0].push_back(node->val);
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
