//
// Created by 阳寜 on 2024/5/17.
//
#include<bits/stdc++.h>

typedef long long ll;
using namespace std;

/**
 * Definition for singly-linked list.
*/
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        // headA 和 headB都往后遍历，可能出现三种情况：
        // headA先到末尾或headB先到末尾或两个同时到末尾
        ListNode *headAA = headA, *headBB = headB;
        while (headAA != headBB) {
            //两链表同时到末尾则不相交
            if (headAA == nullptr && headBB == nullptr) {
                return nullptr;
            }
            //headA先到末尾
            if (headAA == nullptr) {
                headAA = headB;
                headBB = headBB->next;
            }
            else if (headBB == nullptr) {
                headBB = headA;
                headAA = headAA->next;
            }
            else {
                headAA = headAA->next;
                headBB = headBB->next;
            }
        }
        return headAA;
    }
};