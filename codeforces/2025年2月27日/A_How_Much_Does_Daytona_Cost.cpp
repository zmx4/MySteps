#include <bits/stdc++.h>
#define endl "\n"
#define ll long long
using namespace std;

void solve()
{
    int n, k;
    cin >> n >> k;
    vector<int> a(n);
    for (int i = 0; i < n; i++)
        cin >> a[i];
    
    // 若数组中完全没有 k, 则不可能存在合法子段
    bool foundK = false;
    for (int x : a) {
        if (x == k) { foundK = true; break; }
    }
    if (!foundK) {
        cout << "NO" << endl;
        return;
    }
    
    // 构造前缀和，用于每个数字出现次数统计
    // 由于 1<=a[i]<=100, 所以构造prefix[i][x]: 表示前i个元素中数字x的出现次数.
    vector<vector<int>> prefix(n+1, vector<int>(101, 0));
    for (int i = 0; i < n; i++) {
        for (int d = 1; d <= 100; d++)
            prefix[i+1][d] = prefix[i][d];
        prefix[i+1][ a[i] ]++;
    }
    
    // 遍历所有子段
    for (int L = 0; L < n; L++) {
        for (int R = L; R < n; R++) {
            int freqK = prefix[R+1][k] - prefix[L][k];
            if (freqK == 0)
                continue; // 子段中不含 k, 跳过
            bool valid = true;
            for (int d = 1; d <= 100; d++) {
                if (d == k) continue;
                int freqd = prefix[R+1][d] - prefix[L][d];
                if (freqd >= freqK) {
                    valid = false;
                    break;
                }
            }
            if (valid) {
                cout << "YES" << endl;
                return;
            }
        }
    }
    cout << "NO" << endl;
}

signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr),cout.tie(nullptr);
    char readBuffer[1 << 20];
    cin.rdbuf()->pubsetbuf(readBuffer, sizeof(readBuffer));

    int T;cin>>T;
    while(T--)
    {
        solve();
    }
    
    return 0;
}