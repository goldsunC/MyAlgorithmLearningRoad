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
    string convert(string s, int numRows) {
        if (numRows == 1) return s;
        vector<string> strings(numRows,"");
        bool advance = true;
        int j = 0;
        for (int i = 0; i < s.size(); ++i) {
            strings[j].push_back(s[i]);
            if (advance) {
                j++;
            }else {
                j--;
            }
            if (j == 0 || j == numRows - 1) advance = !advance;
        }
        string ans = "";
        for (int i = 0; i < strings.size(); ++i) {
            ans += strings[i];
        }
        return ans;
    }
};