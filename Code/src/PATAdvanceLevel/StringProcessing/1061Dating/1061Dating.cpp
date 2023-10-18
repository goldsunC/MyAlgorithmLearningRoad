//
// Created by 阳寜 on 2023/3/9.
//
#include<bits/stdc++.h>

using namespace std;


int main()
{
    string wek[7] = { "MON","TUE","WED","THU","FRI","SAT","SUN" };
    string a, b;
    cin >> a >> b;

    //1.判断星期几
    int k = 0;
    while (1)
    {
        if (a[k] == b[k] && a[k] >= 'A' && a[k] <= 'G')    break;
        k++;
    }
    cout << wek[a[k] - 'A'] << " ";

    //2.判断多少小时
    k++;
    while (1)
    {
        if (a[k] == b[k] && (a[k] >= '0' && a[k] <= '9' || a[k] >= 'A' && a[k] <= 'N')) break;
        k++;
    }
    printf("%02d:", a[k] <= '9' ? a[k] - '0' : a[k] - 'A' + 10);

    //3.判断多少分钟
    k = 0;
    string c, d;
    cin >> c >> d;
    while (1)
    {
        if (c[k] == d[k] && (c[k] >= 'A' && c[k] <= 'Z' || c[k] >= 'a' && c[k] <= 'z'))
            break;
        k++;
    }
    printf("%02d\n", k);

    return 0;
}
