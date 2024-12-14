#include <bits/stdc++.h>
#define endl "\n"
using namespace std;
struct hash_pair
{
	size_t operator()(const pair<int, int> &p) const
	{
		auto hash1 = hash<int>{}(p.first);
		auto hash2 = hash<int>{}(p.second);
		return hash1 ^ hash2;
	}
};
int park[20005][205];
int FinalState[205];
unordered_set<pair<int, int>, hash_pair> removedPos;
unsigned seed;
unsigned rnd()
{
	unsigned ret = seed;
	seed ^= seed << 13;
	seed ^= seed >> 17;
	seed ^= seed << 5;
	return ret;
}

signed main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);cout.tie(nullptr);
	memset(park, 0, sizeof(park));
	memset(FinalState, 0, sizeof(FinalState));
	int n, m, k;
	cin >> n >> m >> k >> seed;
	for (int i = 1; i <= k;i++)
	{
		int op = (rnd() % 2) + 1;
		if(op==1)
		{
			int i = (rnd() % m) + 1;
			int x = (rnd() % (n * m)) + 1;
			/*
			for(int j=1;j<=n;j++)
			{
				if(park[j][i]==0)
				{
					park[j][i] = x;
				}
			}
			*/
			FinalState[i] = x;
			removedPos[i].clear();
		}
		if(op==2)
		{
			int a = (rnd() % n) + 1;
			int b = (rnd() % m) + 1;
			//park[a][b] = 0;
			removedPos.insert(make_pair(a, b));
		}
	}
	unsigned sum = 0;
	/*
	for (int i = 1; i <= n;i++)
	{
		for(int j=1;j<=m;j++)
		{
			sum^=park[i][j]*((i-1)*m+j);
		}
	}
	*/
	/*
	for(int i = 1; i <= m; i++)
	{
		if(FinalState[i]==0)
		{
			continue;
		}
		for(int j = 1; j <= n; j++)
		{
			if(removedPos[i].find(j)==removedPos[i].end())
			{
				unsigned a = FinalState[i];
				unsigned b = ((j - 1) * m + (i - 1)) + 1;
				sum ^= a * b;
			}
			
		}
	}
	cout << sum << endl;
	*/
	for (int i = 1; i <= m; i++)
	{
		if (FinalState[i] == 0)
		{
			continue;
		}
		for (int j = 1; j <= n; j++)
		{
			if (removedPos[i].find(j) == removedPos[i].end())
			{
				unsigned a = FinalState[i];
				unsigned b = ((j - 1) * m + (i - 1)) + 1;
				sum ^= a * b;
			}
		}
	}
	cout << sum << endl;
	return 0;
}