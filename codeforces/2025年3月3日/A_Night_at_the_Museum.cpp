#include <bits/stdc++.h>
#define endl "\n"
#define ll long long
using namespace std;

signed main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr),cout.tie(nullptr);

    string s;
    cin >> s;
    int ans = 0;
    for(int i = 0; i < s.size(); i++)
    {
        if(i == 0)
        {
            ans += min(abs(s[i] - 'a'), abs('z' - s[i]) + 1);
        }
        else
        {
            ans += min(abs(s[i] - s[i - 1]), 26 - abs(s[i] - s[i - 1]));
        }
    }
    cout << ans << endl;
	return 0;
}