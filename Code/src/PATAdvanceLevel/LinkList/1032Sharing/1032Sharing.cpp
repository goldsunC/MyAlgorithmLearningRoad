//
// Created by 阳寜 on 2023/3/7.
//
#include<bits/stdc++.h>
const int maxN = 100010;
using namespace std;
//链表节点
struct NODE{
    char data;
    int next;
    bool flag;
}node[maxN];

int main() {
    for (auto & i : node) {
        i.flag = false;
    }
    int str1,str2,n;    //两条链表首地址及总节点数
    cin >> str1 >> str2 >> n;
    int address, next;  //节点地址、后继节点地址
    char data;  //data
    for (int i = 0; i < n; ++i) {
        cin >> address >> data >> next;
        node[address].data = data;
        node[address].next = next;
    }
    int p;
    for (p = str1; p != -1; p = node[p].next) {
        node[p].flag = true;
    }
    for (p = str2; p != -1; p = node[p].next) {
        if (node[p].flag) break;
    }
    if (p != -1) {
        printf("%05d\n",p);
    } else {
        printf("-1\n");
    }
    return 0;
}
