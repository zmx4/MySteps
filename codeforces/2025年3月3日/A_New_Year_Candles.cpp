#include <bits/stdc++.h>
#define endl "\n"
#define ll long long
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int a, b;
    cin >> a >> b;
    int hours = a;
    while(a >= b)
    {
        int new_candles = a / b;      // 用 a 个熄灭的蜡烛可以兑换烛数
        hours += new_candles;         // 累加新蜡烛燃烧的小时数
        a = new_candles + a % b;      // 更新剩余的熄灭蜡烛，包括兑换后剩余的
    }
    cout << hours << endl;
    return 0;
}