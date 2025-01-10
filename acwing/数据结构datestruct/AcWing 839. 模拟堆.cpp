#include <bits/stdc++.h>
#define endl "\n"
#define ll long long
using namespace std;

const int N = 1e5 + 10;
int ssize;
int heap[N],ph[N],hp[N];
int n, m;

void heap_swap(int a, int b)
{
	swap(ph[hp[a]], ph[hp[b]]);
	swap(hp[a], hp[b]);
	swap(heap[a], heap[b]);
}

void down(int u)
{
	int t = u;
	if (u * 2 <= ssize && heap[u * 2] < heap[t])
		t = u * 2;
	if (u * 2 + 1 <= ssize && heap[u * 2 + 1] < heap[t])
		t = u * 2 + 1;
	if (t != u)
	{
		heap_swap(u, t);
		down(t);
	}
}

void up(int u)
{
	while (u / 2 && heap[u / 2] > heap[u])
	{
		heap_swap(u, u / 2);
		u /= 2;
	}
}



signed main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);cout.tie(nullptr);

	cin >> n;
	while(n--)
	{
		string op;
		int k, x;
		cin >> op;
		if (op == "I")
		{
			cin >> x;
			heap[++ssize] = x;
			hp[ssize] = m;
			ph[m] = ssize;
			up(ssize);
		}
		else if (op == "PM")
		{
			cout << heap[1] << endl;
		}
		else if (op == "DM")
		{
			heap_swap(1, ssize);
			ssize--;
			down(1);
		}
		else if (op == "D")
		{
			cin >> k;
			k = ph[k];
			heap_swap(k, ssize);
			ssize--;
			up(k);
			down(k);
		}
		else
		{
			cin >> k >> x;
			k = ph[k];
			heap[k] = x;
			up(k);
			down(k);
		}
	}

	return 0;
}