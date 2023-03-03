//
// Created by 阳寜 on 2023/3/3.
//
#include "iostream"
using namespace std;
int main() {
    int a,b;
    cin >> a >> b;

    string x = to_string(a+b);
    string res = "";
    for (int i = x.size() -1 ,j=0; i >=0; i--) {
        j++;
        res = x[i] + res;

        if (j%3 == 0 && i && x[i-1] != '-') res = "," + res;
    }
    cout << res << endl;
}