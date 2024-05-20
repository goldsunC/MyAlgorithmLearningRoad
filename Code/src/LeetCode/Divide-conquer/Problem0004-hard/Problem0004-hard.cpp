//
// Created by 阳寜 on 2023/10/23.
//
#include<bits/stdc++.h>

using namespace std;

//给定两个大小分别为 m 和 n 的正序（从小到大）数组 nums1 和 nums2。请你找出并返回这两个正序数组的 中位数 。
//
//算法的时间复杂度应该为 O(log (m+n)) 。

class Solution {
public:
    /*
     * 初始思路：双指针
     * 维护两个指针，初始在两个数组的起始位置，每次让数值更小的往后移动
     * 如果一个移动到末尾，移动另一个。
     * 首先根据两个数组长度计算出中位数位置，则移动到指定位置即可。
     * 时间复杂度O(m+n)，因为计算两个数组长度都需要O(m+n)
     * */
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int point1 = 0, point2 = 0;
        int mid = (nums1.size() + nums2.size()) / 2;
        bool midIsOdd = true;
        if (mid % 2 == 0) midIsOdd = false;
        //如果mid为奇数，该位置的数字刚好为答案
        //如果mid为偶数，答案为(该位置数字+前一位数字)/2；
        double ans = 0;
        int m = nums1.size(), n = nums2.size();
        while (mid != 0 && point1 != m && point2 != n) {
            nums1[point1] > nums2[point2] ? point2++ : point1++;
            mid--;
        }
        if (mid == 0) {

        }
        if (point1 == m) {

        }
        if (point2 == n) {

        }

    }
};

