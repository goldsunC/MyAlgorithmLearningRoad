//
// Created by 阳寜 on 2023/10/24.
//
#include<iostream>
#include <stdio.h>
#include <stdlib.h>
// TODO:案例过了一半，55分，需要继续改进
int intervalNum(int pointArray[],int arrayNum,int left,int right) {
    int k = 0;
    for (int i = 0; i < arrayNum; ++i) {
        if (pointArray[i] >= left && pointArray[i] <= right) k++;
    }
    return k;
}

int main() {

using namespace std;
    int n,m;
    cin >> n >> m;
    int pointArray[n];
    int interval[m][2];
    for (int i = 0; i < n; ++i) {
        cin >> pointArray[i];
    }
    for (int i = 0; i < m; ++i) {
        cin >> interval[i][0] >> interval[i][1];
    }

    for (int i = 0; i < m; ++i) {
        cout << intervalNum(pointArray,n,interval[i][0],interval[i][1]) <<endl;
    }
    return 0;
}
