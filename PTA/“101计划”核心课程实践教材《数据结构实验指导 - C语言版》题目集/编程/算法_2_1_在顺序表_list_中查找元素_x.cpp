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
    for (int i = 0; i < n; i++)
    {
        int x;
        cin >> x;
        l.push_back(x);
    }
    int x;
    cin >> x;
    auto it = find(l.begin(), l.end(), x);
    if (it == l.end())
    {
        cout << "-1" << endl;
    }
    else
    {
        cout << distance(l.begin(), it) << endl;
    }

	return 0;
}