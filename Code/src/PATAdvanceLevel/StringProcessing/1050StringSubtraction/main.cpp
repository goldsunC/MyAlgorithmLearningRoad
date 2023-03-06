//
// Created by 阳寜 on 2023/3/4.
//
#include<bits/stdc++.h>
using namespace std;

int main()
{
    //  getline()方法：读取一行，包括空白符。
    //  cin：尾部空白符不读
    string a, b;
    getline(cin, a);
    getline(cin, b);

    //将b中所有字符放入哈希表标记
    unordered_map<char, bool> st;
    for (char i : b)
        st[i] = true;

    //枚举a中每个字符观察是否在哈希表中出现过
    string res = "";
    for (char i : a)
        if (!st.count(i))
            res += i;
    cout << res << endl;

    return 0;
}
