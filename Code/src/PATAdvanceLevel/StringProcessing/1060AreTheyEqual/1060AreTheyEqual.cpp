//
// Created by 阳寜 on 2023/3/7.
//
#include<bits/stdc++.h>
//基本思路：直接将A,B两个字符串转换为科学计数法形式，然后对比即可
using namespace std;


/*
 * 合并小数点两侧，第一位0.不用管，需要让第二位为非0数
 * A为待转化为科学计数法的字符串，N为保留有效数字
 * */

string numToScience(string A , int N) {
    int point;  //point为小数点位置
    point = A.find('.');    //find没找到则返回last，即-1
    if (point == -1) A += '.';
    point = A.find('.');
    //s:合并后的字符串
    string s = A.substr(0,point) + A.substr(point+1);
    //消去0.和有效数字之间的0
    while (s.size() && s[0] == '0') {
        s = s.substr(1);
        point--;
    }
    if (s.empty()) point = 0;
    if (s.size() > N) s = s.substr(0,N);
    else s += string(N - s.size() , '0');
    return "0." + s + "*10^" + to_string(point);
}


int main() {
    int N;
    string A,B;
    cin >> N >> A >> B;
    A = numToScience(A,N);
    B = numToScience(B,N);
    if (A == B) cout << "YES " << A << endl;
    else cout << "NO " << A << " " << B << endl;

    return 0;
}
