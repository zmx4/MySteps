#include <bits/stdc++.h>
#define endl "\n"
using namespace std;

/*
def rnd():
	p=(1<<32)
	ret=seed
	seed=(seed xor ((seed<<13) mod p)) mod p
	seed=(seed xor ((seed>>17) mod p)) mod p
	seed=(seed xor ((seed<<5) mod p)) mod p
	return ret
*/
int park[20005][205];
unsigned seed;
unsigned rnd(int seed)
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
	int n, m, k;
	cin >> n >> m >> k >> seed;
	for (int i = 1; i <= k;i++)
	{
		int op = (rnd(seed) % 2) + 1;
		if(op==1)
		{
			int i = (rnd(seed) % m) + 1;
			int x = (rnd(seed) % (n * m)) + 1;
			for(int j=1;j<=n;j++)
			{
				if(park[j][i]==0)
				{
					park[j][i] = x;
				}
			}
		}
		if(op==2)
		{
			int a = (rnd(seed) % n) + 1;
			int b = (rnd(seed) % m) + 1;
			park[a][b] = 0;
		}
	}
	unsigned sum = 0;
	for (int i = 1; i <= n;i++)
	{
		for(int j=1;j<=m;j++)
		{
			sum+=park[i][j]*((i-1)*m+j);
		}
	}
	cout << sum << endl;
	return 0;
}