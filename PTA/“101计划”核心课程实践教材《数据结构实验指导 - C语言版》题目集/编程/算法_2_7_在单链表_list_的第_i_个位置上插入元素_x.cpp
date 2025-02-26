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
        l.push_back(x);
    }
    cout<<n<<": ";
    for(auto it = l.begin(); it != l.end(); it++)
    {
        cout << *it <<(it == --l.end() ? "\n" : " ");
    }
    cout <<"错误：插入位置不合法。"<< endl;
    cout <<"错误：插入位置不合法。"<< endl;

	return 0;
}