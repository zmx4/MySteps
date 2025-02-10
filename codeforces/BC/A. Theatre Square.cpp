#include <bits/stdc++.h>
using namespace std;
int main()
{
	long long int x, y, a; cin >> x >> y >> a;
	long long int cnt = 0, cnti = 0, cntj = 0;
	for (int j = 0; j < y; j += a)
	{
		cntj++;
	}
    for(int i = 0;i < x;i += a)
    {
		cnti++;
	}
	cout << cnti*cntj;
}

