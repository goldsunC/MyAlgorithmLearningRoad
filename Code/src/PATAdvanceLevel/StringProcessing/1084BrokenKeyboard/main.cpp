//
// Created by 阳寜 on 2023/3/10.
//
#include<bits/stdc++.h>

using namespace std;

char charToLower(char ch) {
    if (ch >= 'A' && ch <= 'Z') return ch + 32;
    return ch;
}
char charToUpper(char ch) {
    if (ch >= 'a' && ch <= 'z') return ch - 32;
    return ch;
}

//  思路：双指针同时又移动，如果两字符不等，则原字符串字符破损
//  设置一个打印过字符的Set集合，每次打印前确定是否打印过
int main() {

    string originalString,realString;
    unordered_set<char> printedSet;

    cin >> originalString >> realString;

    int str1Point = 0,str2Point = 0;
    int num = originalString.size();
    for (int i = 0; i < num; ++i) {
        if (originalString[str1Point] == realString[str2Point]) {
            str1Point++;
            str2Point++;
            continue;
        } else {
            if (printedSet.count(charToUpper(originalString[str1Point]))) {
                str1Point++;
            }else {
                cout << charToUpper(originalString[str1Point]);
                printedSet.insert(charToUpper(originalString[str1Point]));
                str1Point++;
            }
        }
    }

    return 0;
}
