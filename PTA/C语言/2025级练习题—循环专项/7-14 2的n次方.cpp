#include <bits/stdc++.h>
#define endl "\n"
using ll = long long;
using ull = unsigned long long;
using LL = long long;
using namespace std;
const int inf = 0x3f3f3f3f;
const int N = 1e5+10;

signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr),cout.tie(nullptr);

    int n;
    while(cin>>n)
    {
        if(n == 0){
            cout << "No!" << endl;
            continue;
        }
        int temp = 1;
        int cnt = 0;
        n = abs(n);
        while(temp < n)
        {
            temp *= 2;
            cnt++;
        }
        if(temp == n)
            cout << cnt << endl;
        else
            cout << "No!" << endl;
    }

    return 0;
}