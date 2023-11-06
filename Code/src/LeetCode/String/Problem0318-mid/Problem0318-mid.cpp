//
// Created by 阳寜 on 2023/11/6.
//
#include<bits/stdc++.h>

using namespace std;

//超时代码：
//class Solution {
//public:
//    int maxProduct(vector<string>& words) {
//        int maxProduct = 0;
//        for (int i = 0; i < words.size(); ++i) {
//            for (int j = i+1; j < words.size(); ++j) {
//                if (!isEqual(words[i],words[j])) {
//                    if (maxProduct < words[i].size() * words[j].size()) {
//                        maxProduct = words[i].size() * words[j].size();
//                    }
//                }
//            }
//        }
//        return maxProduct;
//    }
//    bool isEqual(string str1,string str2) {
//        for (int i = 0; i < str1.size(); ++i) {
//            for (int j = 0; j < str2.size(); ++j) {
//                if (str1[i] == str2[j]) return true;
//            }
//        }
//        return false;
//    }
//};

class Solution {
public:
    int maxProduct(vector<string>& words) {
        int length = words.size();
        vector<int> masks(length);
        for (int i = 0; i < length; i++) {
            string word = words[i];
            int wordLength = word.size();
            for (int j = 0; j < wordLength; j++) {
                masks[i] |= 1 << (word[j] - 'a');
            }
        }
        int maxProd = 0;
        for (int i = 0; i < length; i++) {
            for (int j = i + 1; j < length; j++) {
                if ((masks[i] & masks[j]) == 0) {
                    maxProd = max(maxProd, int(words[i].size() * words[j].size()));
                }
            }
        }
        return maxProd;
    }
};

int main() {
    Solution solution;
    vector<string> words = {"abcw","baz","foo","bar","xtfn","abcdef"};
    cout << solution.maxProduct(words);
    return 0;
}
