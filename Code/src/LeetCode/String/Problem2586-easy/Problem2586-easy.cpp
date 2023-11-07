//
// Created by 阳寜 on 2023/11/7.
//
#include<bits/stdc++.h>

using namespace std;
class Solution {
public:
    int vowelStrings(vector<string>& words, int left, int right) {
        int ans = 0;
        for (int i = left; i <= right; ++i) {
            if (isVowel(words[i][0]) && isVowel(words[i][words[i].size()-1])) {
                ans++;
            }
        }
        return ans;
    }
    bool isVowel(char ch) {
        if (ch == 'a' || ch =='e' || ch == 'i' || ch == 'o' ||ch =='u') return true;
        return false;
    }
};
int main() {


    return 0;
}
