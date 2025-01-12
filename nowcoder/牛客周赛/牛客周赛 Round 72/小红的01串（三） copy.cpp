#include <bits/stdc++.h>
using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	int T;
	cin >> T;
	while (T--)
	{
		int a, b, k;
		cin >> a >> b >> k;
		if (k < abs(a - b) || k > a + b - 1)
		{
			cout << "-1" << endl;
			continue;
		}
		string ans = "";
		char longC, shortC;
		int cntlongC, cntshortC;
		if (a >= b)
		{
			longC = '0';
			shortC = '1';
			cntlongC = a;
			cntshortC = b;
		}
		else
		{
			longC = '1';
			shortC = '0';
			cntlongC = b;
			cntshortC = a;
		}

		int transitions = k;
		int total_chars = a + b;
		int blocks = transitions + 1;

		int base = cntlongC / blocks;
		int extra = cntlongC % blocks;

		vector<int> block_sizes(blocks, base);
		for (int i = 0; i < extra; i++)
			block_sizes[i]++;

		for (int i = 0; i < blocks; i++)
		{
			for (int j = 0; j < block_sizes[i]; j++)
				ans += longC;
			if (i < transitions && cntshortC > 0)
			{
				ans += shortC;
				cntshortC--;
			}
		}

		while (cntshortC > 0)
		{
			ans += shortC;
			cntshortC--;
		}

		cout << ans << endl;
	}

	return 0;
}