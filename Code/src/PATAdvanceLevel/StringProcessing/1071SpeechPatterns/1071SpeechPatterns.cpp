//
// Created by 阳寜 on 2023/3/9.
//
#include<bits/stdc++.h>

using namespace std;

//检查输入字符合法性
bool check(char a) {
    if (a >= '0' && a <= '9') return true;
    if (a >= 'a' && a <= 'z') return true;
    if (a >= 'A' && a <= 'Z') return true;
    return false;
}
char charToLower(char a) {
    if (a >= 'A' && a <= 'Z')
        return a + 32;
    return a;
}

int main() {
    unordered_map<string , int> map;
    string str;
    getline(cin,str);

    //  分割单词并加入hash表
    for (int i = 0; i < str.size(); ++i) {
        if (check(str[i])) {
            string res;
            while (i < str.size() && check(str[i])) {
                res += charToLower(str[i++]);
            }
            map[res]++;
        }
    }
    //  找到出现次数最多的单词
    string ans;
    int cnt = -1;
    for(auto t : map) {
        if (t.second > cnt) cnt = t.second,ans = t.first;
        if (t.second == cnt) {
            if (t.first[0] < ans[0]) {
                cnt = t.second;
                ans = t.first;
            }
        }
    }
    cout << ans << " " << cnt << endl;


    return 0;
}
