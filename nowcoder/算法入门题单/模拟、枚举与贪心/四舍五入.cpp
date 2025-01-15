#include <bits/stdc++.h>
#define endl "\n"
#define ll long long
using namespace std;

string jw(string s)
{
	bool carry = true;
	int p = s.size() - 1;
	while (p >= 0)
	{
		int d = s[p] - '0' + carry;
		carry = (d > 9);
		s[p] = '0' + d % 10;
		p--;
	}
	if (carry)
		s = "1" + s;
	return s;
}
int n, t;
string num;
signed main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr),cout.tie(nullptr);

	
	cin >> n >> t;
	
	cin >> num;
	int carry = 0, carryx = 0;

	int i = num.find('.');
	if (i == -1)
	{
		cout << num << endl;
		return 0;
	}
	i++;
	for(;i<num.length();i++)
	{
		if(num[i]>='5')
		{
			num.erase(i--);
			t--;
			while (num[i] == '4' && t--)
				num.erase(i--);
			if (num[i] == '.')
			{
				num.erase(i--);
				while (num[i] == '9')
					num[i--] = '0';
				if(i==-1)
					cout << 1;
				else
					num[i]++;
			}
			else
				num[i]++;
		}
	}
	
	cout << num << endl;
	return 0;
}