#include <bits/stdc++.h>
#define endl "\n"
#define ll long long
using namespace std;

signed main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr),cout.tie(nullptr);

    int n, k;
    cin >> n >> k;
    int cnt = 0;
    for(int i = 0; i < n; i++)
    {
        int x;
        cin >> x;
        if(5 - x >= k)
            cnt++;
    }
    cout << cnt / 3 << endl;
	return 0;
}