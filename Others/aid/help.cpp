#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> PII;
#define sc scanf
#define ff first
#define ss second

void solve()
{
    int n, k;
    cin >> n >> k;
    vector<int> p(n);
    for (int i = 0; i < n; i++)
        cin >> p[i];
    sort(p.begin(), p.end());
    int fl = 0;
    if (p[n - 1] - p[0] > k)
    {
        fl = 1;
        if (p[n - 1] - 1 - p[0] > k)
        {
            cout << "Jerry" << endl;
            return;
        }
        else
        {
            if (p[n - 2] - p[0] > k)
            {
                cout << "Jerry" << endl;
                return;
            }
        }
    }
    if (n % 2 == 0)
    {
        cout << "Jerry" << endl;
    }
    else
    {
        cout << "Tom" << endl;
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    cin >> t;
    while (t--)
        solve();
    return 0;
}