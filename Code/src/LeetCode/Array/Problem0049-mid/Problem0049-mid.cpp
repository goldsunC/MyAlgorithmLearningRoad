//
// Created by 阳寜 on 2024/3/19.
//
#include<bits/stdc++.h>

typedef long long ll;
using namespace std;

/*
 * 思路：字母异位词排序后应该为一样的单词。
 * 因此可以将所有单词排序，然后将排序后的单词作为键存储到哈希表
 * 遍历所有排序过的单词，如果存在该键，则对应值的列表加入原单词。否则作为新键存储哈希表
 * */
class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        // 无序哈希表
        unordered_map<string , vector<string>> mp;
        // 遍历所有单词并将其进行排序存入哈希表
        for(string& str: strs) {
            string key = str;   //将复制的str作为key并进行处理
            sort(key.begin(), key.end());
            mp[key].emplace_back(str);
        }
        vector<vector<string>> ans;
        for(auto it = mp.begin(); it != mp.end(); ++it) {
            ans.emplace_back(it->second);
        }
        return ans;
    }
};