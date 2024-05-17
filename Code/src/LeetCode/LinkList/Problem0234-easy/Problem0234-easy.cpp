//
// Created by 阳寜 on 2024/5/17.
//
#include<bits/stdc++.h>

/**
 *  Definition for singly-linked list.
*/
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

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
    //无脑思路，遍历进数组双指针判断。skip
    //进阶：时间O(n)空间O(1) 下意识思路，后半段反转，然后双指针顺序判断
    bool isPalindrome(ListNode* head) {
        if (head == nullptr) return true;
        //直接双指针，分别走1步和两步，刚好一个末尾一个中间，同时能算出来链表长度
        ListNode *quick = head, *slow = head;
        int length = 1;
        while (quick->next != nullptr) {
            quick = quick->next;
            slow = slow->next;
            ++length;
            if (quick->next != nullptr) {
                quick = quick->next;
                ++length;
            }
        }
        ListNode *rightList(0);
        //上述的慢指针当length为偶数，刚好指向后半段链表，如果为奇数，指向链表的正中间节点
        if (length % 2 == 0) {
            rightList = reverseList(slow);
        }else {
            rightList = reverseList(slow->next);
        }
        ListNode *leftList = head;
        while (leftList && rightList != nullptr) {
            if (leftList->val != rightList->val) {
                return false;
            }
            leftList = leftList->next;
            rightList = rightList->next;
        }
        return true;
    }
    ListNode* reverseList(ListNode* head) {
        //反转链表的工具方法，返回的是反转后的链表头
        ListNode* prev = nullptr;
        ListNode* curr = head;
        while (curr) {
            ListNode* next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
        }
        return prev;
    }
};