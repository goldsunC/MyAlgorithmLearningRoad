//
// Created by 阳寜 on 2023/11/17.
//
#include<bits/stdc++.h>

typedef long long ll;
using namespace std;

struct ListNode{
    int val;
    ListNode * next;
    ListNode():val(0),next(nullptr){}
    ListNode(int x,ListNode * next):val(x),next(next){}
};
// 没有给出链表长度，如果不想遍历一遍链表查出总长度，
// 则需要用到双指针，左指针走一步，右指针走两步。
class Solution {
public:
    ListNode* deleteMiddle(ListNode* head) {
        // 链表只有一个结点，直接返回空结点
        if (!head->next) return nullptr;
        ListNode * h = new ListNode();
        h->next = head;
        ListNode * leftP = h;
        // 先让右指针走两步，因为删除结点需要直到该节点前一个结点的位置
        ListNode * rightP = h;
        while (rightP->next) {
            rightP = rightP->next;
            if (!rightP->next) break;
            rightP = rightP->next;
            leftP = leftP->next;
        }
        leftP->next = leftP->next->next;
        return h->next;
    }
};