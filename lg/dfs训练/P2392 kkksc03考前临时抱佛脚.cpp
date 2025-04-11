#include <bits/stdc++.h>
#define endl "\n"
using ll = long long;
using ull = unsigned long long;
using namespace std;
const int inf = 0x3f3f3f3f;
int s1, s2, s3, s4;
const int N = 30;
int a[N],b[N],c[N],d[N];
int l = 0,r = 0;
int minn = 0x3f3f3f3f;
void searchs1(int u)
{
	if(u > s1)
	{
		minn = min(minn,max(l ,r));
		return;
	}
	l += a[u];
	searchs1(u + 1);
	l -= a[u];
	r += a[u];
	searchs1(u + 1);
	r -= a[u];

}
void searchs2(int u)
{
	if(u > s2)
	{
		minn = min(minn,max(l ,r));
		return;
	}
	l += b[u];
	searchs2(u + 1);
	l -= b[u];
	r += b[u];
	searchs2(u + 1);
	r -= b[u];
}
void searchs3(int u)
{
	if(u > s3)
	{
		minn = min(minn, max(l, r));
		return;
	}
	l += c[u];
	searchs3(u + 1);
	l -= c[u];
	r += c[u];
	searchs3(u + 1);
	r -= c[u];
}
void searchs4(int u)
{
	if(u > s4)
	{
		minn = min(minn, max(l, r));
		return;
	}
	l += d[u];
	searchs4(u + 1);
	l -= d[u];
	r += d[u];
	searchs4(u + 1);
	r -= d[u];
}


signed main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr),cout.tie(nullptr);

	cin>> s1 >> s2 >> s3 >> s4;
	for(int i = 1; i <= s1; i++)
	{
		cin >> a[i];
	}
	for(int i = 1; i <= s2; i++)
	{
		cin >> b[i];
	}
	for(int i = 1; i <= s3; i++)
	{
		cin >> c[i];
	}
	for(int i = 1; i <= s4; i++)
	{
		cin >> d[i];
	}
	int ans = 0;
	l = 0,r = 0;
	minn = 0x3f3f3f3f;
	searchs1(1);
	ans+= minn;
	l = 0,r = 0;
	minn = 0x3f3f3f3f;
	searchs2(1);
	ans+= minn;
	l = 0,r = 0;
	minn = 0x3f3f3f3f;
	searchs3(1);
	ans+= minn;
	l = 0,r = 0;
	minn = 0x3f3f3f3f;
	searchs4(1);
	ans+= minn;
	cout << ans << endl;
	return 0;
}
//WA
/*
signed main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr),cout.tie(nullptr);

	cin>> s1 >> s2 >> s3 >> s4;
	for(int i = 1; i <= s1; i++)
	{
		cin >> a[i];
	}
	for(int i = 1; i <= s2; i++)
	{
		cin >> b[i];
	}
	for(int i = 1; i <= s3; i++)
	{
		cin >> c[i];
	}
	for(int i = 1; i <= s4; i++)
	{
		cin >> d[i];
	}
	sort(a + 1, a + s1 + 1);
	sort(b + 1, b + s2 + 1);
	sort(c + 1, c + s3 + 1);
	sort(d + 1, d + s4 + 1);
	int ans = 0;
	int l = 1, r = s1;
	while(l<r)
	{
		int cnt = min(a[l], a[r]);
		a[l]-=cnt, a[r]-=cnt;
		if(a[l] == 0)
			l++;
		if(a[r] == 0)
			r--;
		if(a[l] == a[r])
			break;
	}
	ans += a[l];
	//cout << ans << endl;
	//ans += b[l];
	l = 1, r = s2;
	while(l<r)
	{
		int cnt = min(b[l], b[r]);
		b[l]-=cnt, b[r]-=cnt;
		ans+=cnt;
		if(b[l] == 0)
			l++;
		if(b[r] == 0)
			r--;
		if(b[l] == b[r])
			break;
	}
	ans += b[l];
	//cout << ans << endl;
	l = 1, r = s3;
	while(l<r)
	{
		int cnt = min(c[l], c[r]);
		c[l]-=cnt, c[r]-=cnt;
		ans += cnt;
		if(c[l] == 0)
			l++;
		if(c[r] == 0)
			r--;
		if(c[l] == c[r])
			break;
	}
	ans += c[l];
	l = 1, r = s4;
	while(l<r)
	{
		int cnt = min(d[l], d[r]);
		d[l]-=cnt, d[r]-=cnt;
		ans += cnt;
		if(d[l] == 0)
			l++;
		if(d[r] == 0)
			r--;
		if(d[l] == d[r])
			break;
	}
	ans += d[l];
	cout << ans << endl;
	return 0;
}
*/