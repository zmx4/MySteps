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
        l.push_front(x);
    }
    
    int i;
    cin >> i;
    
    if (i <= 0 || i > n)
    {
        cout << -1 << endl;
        return 0;
    }
    
    auto it = l.begin();
    for (int pos = 1; pos < i; pos++)
    {
        ++it;
    }
    
    cout << *it << endl;
    return 0;
}