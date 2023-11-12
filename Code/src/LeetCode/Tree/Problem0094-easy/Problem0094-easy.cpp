//
// Created by 阳寜 on 2023/11/12.
//
#include<bits/stdc++.h>

using namespace std;
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0),left(nullptr),right(nullptr) {}
    TreeNode(int x) : val(x),left(nullptr),right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) :
    val(x), left(left), right(right) {}
};
/*
 * 中序遍历，先左，后根，再右
 * */

// 递归解法
class Solution {
public:
    vector<int> ans={};
    vector<int> inorderTraversal(TreeNode* root) {
        if (!root){
            return ans;
        }
        if (root->left) inorderTraversal(root->left);
        ans.push_back(root->val);
        if (root->right) inorderTraversal(root->right);
        return ans;
    }
};

//  迭代解法，需要用到栈，比递归难理解些
class Solution2 {
public:
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> ans = {};
        if (!root) return ans;
        stack<TreeNode*> st;
        //当根节点不为空，或者栈不为空
        while (root != nullptr || !st.empty()) {
            //根不为空，则一直顺着左孩子将其压入栈中
            while (root != nullptr) {
                st.push(root);
                root = root->left;
            }
            root = st.top();
            st.pop();
            ans.push_back(root->val);
            root = root->right;
        }
        return ans;
    }
};
int main() {
    return 0;
}
