#include <bits/stdc++.h>
using namespace std;

signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    string a;
    cin >> a;
    string suba = "";
    int sign = 1;
    int sum = 0;int flag = 0;
    for (int i = 0; i <= a.size(); i++)
    {
        if (a[i] >= 'a' && a[i] <= 'z')
        {
            a[i] = toupper(a[i]);
            flag = 1;
        }
        if (a[i] <= '9' && a[i] >= '0')
        {
            suba.push_back(a[i]);
            flag = 1;
        }
        else if (a[i] <= 'F' && a[i] >= 'A')
        {
            suba.push_back(a[i]);
            flag = 1;
        }
        if (a[i] == '-'&&flag == 0)
        {
            sign = -1;
        }
    }
    /*
    for (int i = 0; i <= suba.length() - 1; i++)
    {
        sum *= 16;
        if (suba[i] <= '9' && suba[i] >= '0')
            sum += suba[i] - '0';
        if (suba[i] <= 'A' && suba[i] >= 'Z')
            sum += suba[i] - 'A' + 9;
        cout << sum;
    }
    */
    sum = stoi(suba, nullptr, 16);
    sum *= sign;
    cout << sum;
    return 0;
}