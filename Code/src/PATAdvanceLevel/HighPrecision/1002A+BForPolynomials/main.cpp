#include<bits/stdc++.h>
using namespace std;

const int N = 1010;
double a[N], b[N], c[N];

int main()
{
    int k, n;
    double v;

    cin >> k;
    while (k--)  //输入第一组多项式
    {
        cin >> n >> v;
        a[n] = v;
    }

    cin >> k;
    while (k--)  //输入第二组多项式
    {
        cin >> n >> v;
        b[n] = v;
    }

    //将两个多项式对应项相加
    for (int i = 0; i < N; i++)    c[i] = a[i] + b[i];

    k = 0;    //计算相加后多项式非零项的个数
    for (double i : c)
        if (i)
            k++;

    cout << k;
    for (int i = N - 1; i >= 0; i--) //从指数最大的开始输出
        if (c[i])
            printf(" %d %.1f", i, c[i]);

    return 0;
}
