//24-12-1 Tick
#include <bits/stdc++.h>
#define endl "\n"
using namespace std;

struct dradon
{
  int x,y;
};
bool compare(const dradon &a, const dradon &b)
{
	return (a.x < b.x) || (a.x == b.x && a.y < b.y);
}
signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);cout.tie(nullptr);

    int s,n;cin>>s>>n;
	dradon d[n];
    for (int i = 0; i < n; i++)
    {
	    cin>>d[i].x>>d[i].y;
    }
    sort(d,d+n,compare);
	for (int i = 0; i < n; i++)
	{
		if (s>d[i].x)
		{
			s+=d[i].y;
		}
		else
		{
			cout<<"NO"<<endl;
			return 0;
		}
	}
	cout<<"YES"<<endl;
    return 0;
}
