#include <bits/stdc++.h>
#define endl "\n"
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int k, n, w; cin >> k >> n >> w;
    int sum = 0;
    for(int i = 1;i <= w;i++)
    {
        sum += i * k;
    }
    if (n - sum >= 0)cout << "0";
    else cout << sum - n;
    return 0;
}
