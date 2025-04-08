#include <bits/stdc++.h>
#define endl "\n"
using ll = long long;
using ull = unsigned long long;
using namespace std;
const int inf = 0x3f3f3f3f;
vector<int> ans;

void x2()
{
	int carry = 0;
	for(int i = 0;i < ans.size();i++)
	{
		int t = ans[i] * 2 + carry;
		carry = t / 10;
		ans[i] = t % 10;
	}
	if(carry)ans.push_back(carry);
}

signed main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr),cout.tie(nullptr);

	int d;
	string n;
	cin >> d >> n;
	auto it = n.find('.');
	int len = n.size() - it - 1;
	n.erase(it, 1);
	
	//reverse(n.begin(), n.end());
	//for(int i = 0;i < n.size();i++)ans.push_back(n[i] - '0');
	for (char c : n)
	{
		ans.push_back(c - '0');
	}
	reverse(ans.begin(), ans.end());

	while(d--)x2();
	reverse(ans.begin(), ans.end());

	// 四舍五入处理
	int L = ans.size();
	if (len > 0 && ans[L - len] >= 5)
	{
		int i = L - len - 1;
		while (i >= 0)
		{
			ans[i]++;
			if (ans[i] < 10)
				break;
			ans[i] = 0;
			i--;
			if (i < 0)
			{
				ans.insert(ans.begin(), 1);
				break;
			}
		}
	}
	if (len > 0)
		ans.resize(ans.size() - len);

	//ans.erase(ans.begin() + it);
	for(int i = 0;i < ans.size();i++)
	{
		cout << ans[i];
	}
	return 0;
}