#include <bits/stdc++.h>
#define endl "\n"
#define ll long long
using namespace std;

const int N = 100003;
int h[N], e[N], ne[N], idx;

void insert(int x)
{
	int k = (x % N + N) % N;
	e[idx] = x;
	ne[idx] = h[k];
	h[k] = idx++;
}

bool query(int x)
{
	int k = (x % N + N) % N;
	for (int i = h[k]; i != -1; i = ne[i])
		if (e[i] == x)
			return true;
	return false;
}

signed main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);cout.tie(nullptr);

	int n;
	cin >> n;
	memset(h, -1, sizeof h);
	while(n--)
	{
		string op;
		int x;
		cin >> op >> x;
		if (op == "I")
			insert(x);
		else
		{
			if (query(x))
				cout << "Yes" << endl;
			else
				cout << "No" << endl;
		}
	}

	return 0;
}