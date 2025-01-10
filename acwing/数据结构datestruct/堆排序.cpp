#include <bits/stdc++.h>
#define endl "\n"
#define ll long long
using namespace std;

const int N = 1e5 + 10;
int ssize;
int heap[N];
int n, m;

void down(int u)
{
	int t = u;
	if(u * 2 <= ssize && heap[u * 2] < heap[t]) t = u * 2;
	if(u * 2 + 1 <= ssize && heap[u * 2 + 1] < heap[t]) t = u * 2 + 1;
	if(t != u)
	{
		swap(heap[u], heap[t]);
		down(t);
	}
}

void up(int u)
{
	while(u / 2 && heap[u / 2] > heap[u])
	{
		swap(heap[u / 2], heap[u]);
		u /= 2;
	}
}

signed main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);cout.tie(nullptr);

	cin >> n >> m;
	for(int i = 1; i <= n; i++) cin >> heap[i];
	ssize = n;
	for(int i = n / 2; i; i--) down(i);
	while(m--)
	{
		cout<<heap[1]<<' ';
		heap[1] = heap[ssize--];
		down(1);
	}
	return 0;
}