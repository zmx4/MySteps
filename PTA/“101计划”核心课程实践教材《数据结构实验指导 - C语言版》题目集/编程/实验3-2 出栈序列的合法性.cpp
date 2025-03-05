#include <bits/stdc++.h>
#define endl "\n"
#define ll long long
using namespace std;

signed main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr),cout.tie(nullptr);

	int n, m, t;
	cin >> n >> m >> t;
	while(t--)
	{
		vector<int> candidate(n);
		for (int i = 0; i < n; i++)
		{
			cin >> candidate[i];
		}

		vector<int> st; 
		int push = 1;	
		bool valid = true;

		// 模拟出栈过程
		for (int i = 0; i < n; i++)
		{
			int target = candidate[i];
			while ((st.empty() || st.back() != target) && push <= n)
			{
				if (st.size() < (size_t)m)
				{
					st.push_back(push);
					push++;
				}
				else
				{
					break;
				}
			}
			if (!st.empty() && st.back() == target)
			{
				st.pop_back();
			}
			else
			{
				valid = false;
				break;
			}
		}
		cout << (valid ? "YES" : "NO") << "\n";
	}

	return 0;
}