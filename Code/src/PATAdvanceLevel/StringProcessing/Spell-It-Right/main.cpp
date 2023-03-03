//
// Created by 阳寜 on 2023/3/3.
//
#include "iostream"
using namespace std;
int main() {
    string x;
    cin >> x;

    int sum = 0;
    for (auto item:x) sum += item-'0';

    string words[10] = {"zero","one","two","three",
                        "four","five","six","seven",
                        "eight","nine"};

    string res = to_string(sum);
    cout << words[res[0]-'0'];
    for (int i = 1; i < res.size(); i++) {
        cout << " " << words[res[i] - '0'];
    }

    return 0;
}