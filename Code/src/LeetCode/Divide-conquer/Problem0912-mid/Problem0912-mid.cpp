//
// Created by 阳寜 on 2023/11/13.
//
#include<bits/stdc++.h>

using namespace std;
//排序，至少快排和归并一定要能滚瓜烂熟实现
class Solution {
public:
    //快排
    vector<int> sortArray(vector<int>& nums) {
        quickSort(nums,0,nums.size() - 1);
        return nums;
    }
    void quickSort(vector<int> & nums, int left, int right) {
        if (left < right) {
            int pivot = getPivot(nums, left, right);
            quickSort(nums, left, pivot - 1);
            quickSort(nums, pivot + 1, right);
        }
    }
    int getPivot(vector<int> & nums, int left, int right) {
        //  随机中轴
        int temp = nums[(left + right) / 2];
        nums[(left + right) / 2] = nums[left];
        nums[left] = temp;
        int pivot = nums[left];
        while (left < right) {
            while (nums[right] >= pivot && left < right) right--;
            nums[left] = nums[right];
            while (nums[left] < pivot && left < right) left++;
            nums[right] = nums[left];
        }
        nums[right] = pivot;
        return left;
    }
};
int main() {
    return 0;
}
