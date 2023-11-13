//
// Created by 阳寜 on 2023/11/13.
//
#include<bits/stdc++.h>

using namespace std;
struct TreeNode {
    int val;
    TreeNode * left;
    TreeNode * right;
    TreeNode():val(0),left(nullptr),right(nullptr){}
    TreeNode(int x): val(x),left(nullptr),right(nullptr){}
    TreeNode(int x , TreeNode * left , TreeNode * right) :val(x),left(left),right(right){}
};
class Solution {
public:
    int rob(TreeNode* root) {

    }
};

int main() {
    return 0;
}
