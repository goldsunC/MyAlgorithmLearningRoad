//
// Created by 阳寜 on 2024/3/21.
//
#include<bits/stdc++.h>

typedef long long ll;
using namespace std;

/*
 * 初始思路，使用一个哈希表，键作为元素，值作为元素出现的次数。
 * 通过案例1115/1118，案例超时
 * 问题应该在于每次删除的时候需要查询该元素是否存在。
 * */
class FrequencyTracker {
private:
    unordered_map<int, int> initArray;
public:
    FrequencyTracker() {

    }
    void add(int number) {
        ++initArray[number];
    }

    void deleteOne(int number) {
        if (initArray.count(number) != 0) {
            if (initArray[number] >= 0)
                --initArray[number];
        }
    }

    bool hasFrequency(int frequency) {
        for (auto num : initArray) {
            if (num.second == frequency) return true;
        }
        return false;
    }
};

/*
 * 优化思路：使用两个哈希表，一个存元素及元素的出现频率，另一个哈希表存
 * 各个频率出现的次数
 *
 * 每添加一个元素，该元素出现次数＋1，同时该元素出现总次数的次数＋1
 * 嘿嘿嘿
 * */

class optimizedSolution {
private:
    unordered_map<int, int> numFrequency;   //元素出现频率
    unordered_map<int, int> frequencyNum;   //某频率出现次数
public:
    optimizedSolution() {

    }
    void add(int number) {
        --frequencyNum[numFrequency[number]];
        ++frequencyNum[++numFrequency[number]];
    }

    void deleteOne(int number) {
        //如果该元素存在且不为0，那么其出现次数-1，同时其
        //减少后的次数＋1，原出现次数-1
        if (!numFrequency[number])
            return;
            --frequencyNum[numFrequency[number]];
            ++frequencyNum[--numFrequency[number]];
    }

    bool hasFrequency(int frequency) {
        return (frequencyNum[frequency]);
    }
};