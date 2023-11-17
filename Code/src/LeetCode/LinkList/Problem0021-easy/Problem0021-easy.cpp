//
// Created by 阳寜 on 2023/11/17.
//
#include<bits/stdc++.h>

typedef long long ll;
using namespace std;

// Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        ListNode * ans = new ListNode(-1);
        ListNode * pre = ans;
        while (list1 != nullptr && list2 != nullptr) {
            if (list1->val > list2->val) {
                pre->next = list2;
                list2 = list2->next;
            }else{
                pre->next = list1;
                list1 = list1->next;
            }
            pre = pre->next;
        }
        pre->next = list1 == nullptr ? list2 : list1;
        return ans->next;
    }
};