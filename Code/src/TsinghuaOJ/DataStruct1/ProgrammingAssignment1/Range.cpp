//
// Created by 阳寜 on 2023/10/24.
//
#include<iostream>
#include <cstdio>
#include <cstdlib>
/* TODO:案例过了一半，55分，需要继续改进
 * 分析原因：忘了给输入的数轴点排序了，给出的示例是有序的，就默认有序了
 * 算法时间复杂度不够，每次查询区间点个数都是遍历，时间复杂度总共为O(n^2)
 * 可优化为二分查找区间端点的位置，进而计算中间元素个数
 * 因为不让用STL模板，这里使用qsort排序
 */
//qsort比较函数
int compare(const void *a, const void *b) {
    return *(int*)a - *(int*)b;
}
int binSearch(const int *a,int left, int right, int n) {
    while (left < right) {
        int mid = (left + right) >> 1;
        (n < a[mid]) ? right = mid :left = mid + 1;
    }
    return --left;
}
int main() {

using namespace std;
    int n,m;
    int a,b;
    scanf("%d %d", &n, &m);
    int pointArray[n];
    for (int i = 0; i < n; ++i) {
        scanf("%d" , &pointArray[i]);
    }
    qsort(pointArray, n, sizeof(int), compare);
    for (int i = 0; i < m; ++i) {
        scanf("%d %d", &a, &b);
        int left = binSearch(pointArray, 0, n ,a);
        int right = binSearch(pointArray, 0 ,n, b);
        if (pointArray[left] == a && left >= 0) {
            left--;
        }
        printf("%d\n", right - left);
    }

    return 0;
}
