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
     * 思路：把答案进行动态规划更新。
     * 初始为ans[0] 为 0，后续每次判断i - 1
     * 如果i-1最后一位是1，可能为全1，或者穿插0的1
     * 如果是全1，则ans[i] = 1,如果是穿插0的1，则ans[i] = 0前边1的个数 + 1
     * 如果i-1最后一位为0,ans[i] = ans[i-1]+1
     */
    vector<int> countBits(int n) {
        vector<int> ans(n + 1,0);
        for (int i = 1; i <= n; ++i) {
            int j = i - 1;
            if (j & 1) {
                // j 最后一位为1
                if (j & i) { //判断是否为穿插1
                    int pos = 0;
                    //判断最后一个0的位置
                    while (j & 1) {
                        pos++;
                        j /= 2;
                    }
                    ans[i] = ans[i-1] - (pos - 1);
                }else { //全1
                    ans[i] = 1;
                }
            }else {
                // j 最后一位为0
                ans[i] = ans[i - 1] + 1;
            }
        }
        return ans;
    }
};
int main() {
    Solution solution;
    solution.countBits(2);
}