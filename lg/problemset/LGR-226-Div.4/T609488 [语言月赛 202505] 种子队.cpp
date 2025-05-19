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

    int n,k;
    cin >> n >> k;
    unordered_set<int>seed;
    for(int i = 1; i <= k; i++)
    {
        int x;
        cin >> x;
        seed.insert(x);
    }
    int cnt = 0;
    bool ok = true;
    int m = n / k;
    for(int i = 1;i <= k;i++)
    {
        cnt = 0;
        for(int j = 1;j <= m ;j++)
        {
            int x;
            cin >> x;
            if(seed.count(x))
            {
                cnt++;
            }
        }
        if(cnt!=1)
        {
            ok = false;
            //cout<<i<< cnt<<endl;
            break;
            
        }
    }
    if(ok)
    {
        cout << "\"MiaoW\"" << endl;
    }
    else
    {
        cout << "\\QAQ/" << endl;
    }







    return 0;
}