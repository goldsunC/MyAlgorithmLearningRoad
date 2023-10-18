//
// Created by 阳寜 on 2023/3/8.
//
#include<bits/stdc++.h>

using namespace std;


int main() {
    int n,m,now = 0;    //n次停靠，m下一层停靠楼层，now现在停靠楼层
    cin >> n;
    int time;   //需要总时间
    time = 5*n;
    for (int i = 0; i < n; ++i) {
        cin >> m;
        if (m > now) {
            time += 6*(m - now);
            now = m;
        }else if(m < now) {
            time += 4*(now - m);
            now = m;
        }
    }
    cout << time;

    return 0;
}
