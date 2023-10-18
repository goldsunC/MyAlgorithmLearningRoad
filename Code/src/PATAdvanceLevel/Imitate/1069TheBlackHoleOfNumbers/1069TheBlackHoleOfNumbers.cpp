//
// Created by 阳寜 on 2023/3/6.
//
#include<bits/stdc++.h>

using namespace std;

//  sort函数默认排升序
bool cmp(int a , int b) {   //递减排序函数
    return a > b;
}

//  数字转数字数组
void numToArray(int a, int num[]) {
    for (int i = 0; i < 4; ++i) {
        num[i] = a % 10;
        a /= 10;
    }
}

//  数字数组转整数
int arrayToNum(const int num[]) {
    int sum = 0;
    for (int i = 0; i < 4; ++i) {
        sum = sum * 10 + num[i];
    }
    return sum;
}
int main() {
    int n, MIN, MAX;
    cin >> n;
    int num[5];
    while (true) {
        numToArray(n , num);
        sort(num,num+4);
        MIN = arrayToNum(num);
        sort(num , num + 4 , cmp);
        MAX = arrayToNum(num);
        n = MAX - MIN;
        printf("%04d - %04d = %04d\n",MAX,MIN,n);
        if (n == 0 || n == 6174) break;
    }
    return 0;
}
