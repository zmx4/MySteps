#include <bits/stdc++.h>
#define endl "\n"
#define ll long long
using namespace std;

signed main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr),cout.tie(nullptr);

    list<int> l;
    int n;
    cin >> n;
    for(int i = 0; i < n; i++)
    {
        int x;
        cin >> x;
        l.push_front(x);
    }
    int x;
    cin >> x;
    int cnt = 0;
    for(auto it = l.begin(); it != l.end(); it++)
    {
        if(*it == x)
        {
            cout << x << endl;
            return 0;
        }
        cnt++;
    }
    cout << x<<" 未找到。" << endl;

	return 0;
}