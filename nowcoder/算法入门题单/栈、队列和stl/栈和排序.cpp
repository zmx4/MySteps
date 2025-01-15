#include <bits/stdc++.h>
#define endl "\n"
#define ll long long
using namespace std;

signed main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr), cout.tie(nullptr);
	char readBuffer[1 << 20];
	cin.rdbuf()->pubsetbuf(readBuffer, sizeof(readBuffer));

	int n;
	cin >> n;
	stack<int> s;
	int a[n+2], b[n+2];
	memset(b,0,sizeof(b));

	for (int i = 0; i < n; i++)
		cin >> a[i];
	for (int i =n - 1; i >= 0;i--)
		b[i]=max(b[i+1],a[i]);
	/* for (int i = 0; i < n; i++)
		cout<<b[i]<<" ";
	cout<<endl; */
	for(int i=0;i<n;i++)
	{
		s.push(a[i]);
		while(!s.empty()&&s.top()>b[i+1])
		{
			cout<<s.top()<<" ";
			s.pop();
		}
	}
	return 0;
}