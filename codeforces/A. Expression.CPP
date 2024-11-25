//24-11-25 Tick
#include <bits/stdc++.h>
#define endl "\n"
using namespace std;

signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    /*
    int a[3];
    cin >> a[0] >> a[1] >> a[2];
    if (a[2]!=1&&a[0]!=1)
    {
        sort(a, a+3);
        if(a[2]==1)cout << "3";
        else if(a[1]==1)cout << 2*a[2];
        else if(a[0]==1)cout << (1+a[1])*a[2];
        else cout << a[1]*a[0]*a[2];
    }
    else if(a[2]==1&&a[1]!=1&&a[0]!=1)
    {
        sort(a, a+2);
        if(a[1]==1)cout << "3";
        else if(a[0]==1)cout << a[1]+a[0]+a[2];
        else cout << a[0]*(a[1]+a[2]);
    }
    else if(a[1]==1&&a[0]!=1)
    {
        //8 1 4
        if(a[0]==1&&a[2]==1)cout << "3";
        else if(a[0]!=1&&a[2]!=1)
        {
            if((a[0]+1)*a[2]>(a[2]+1)*a[0])cout << (a[0]+1)*a[2];
            else cout << (a[2]+1)*a[0];
        }
        else
        {
            sort(a, a+3);
            cout << a[2]*(a[1]+a[0]);
        }
    }
    else if(a[0]==1)
    {
        if (a[2]!=1)cout << (a[0]+a[1])*a[2];
        else cout << (a[0]+a[1])+a[2];
    }
    */
    int a, b, c;

    // 输入三个整数
    std::cin >> a >> b >> c;

    // 计算所有可能的表达式的值
    int expr1 = a + b + c;
    int expr2 = a + b * c;
    int expr3 = a * b + c;
    int expr4 = a * b * c;
    int expr5 = (a + b) * c;
    int expr6 = a * (b + c);

    // 找出最大值
    int max_value = std::max({expr1, expr2, expr3, expr4, expr5, expr6});

    // 输出最大值
    std::cout << max_value << endl;

    return 0;
}
