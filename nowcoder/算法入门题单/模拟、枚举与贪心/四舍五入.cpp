#include <bits/stdc++.h>
#define endl "\n"
#define ll long long
using namespace std;

signed main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr),cout.tie(nullptr);

	int n, t;
	cin >> n >> t;
	string num;
	cin >> num;
	int carry = 0, carryx = 0;

	size_t i = num.find('.');
	i++;
	while(num[i]!='.'&&t>0)
	{
		if(num[i+1]<='4')
		{
			i++;
			continue;
		}
		else
		{
			if(carryx == 1)
			{
				if (num[i] <= '8')
					num[i]++;
				else
				{
					num[i] = 0;
					i--;
				}
			}
			if(num[i]<='8'&&t>0)
			{
				num[i]++;
				num.erase(i + 1);
				i--, t--;
			}
			else if (num[i] == '9' && t > 0)
			{
				carryx = 1;
				num.erase(i);
				i--, t--;
			}
		}
	}
	
	if (carry == 1)
	{
		size_t index = num.find('.');
		index--;
		if (num[index] <= '8')
			num[index]++, carry--;
		else
		{
			num[index] = 0;
			while (carry == 1 && index - 1 >= 0)
			{
				index--;
				if (num[index] <= '8')
					num[index]++, carry--;
			}
			if (index == 0 && carry == 1)
			{
				num = '1' + num;
			}
		}
	}
	// 去尾随的零
	for(int i=num.length()-1;i>=0;i--)
	{
		if(num[i]=='0')
			num.pop_back();
		else
			break;
	}
	cout << num << endl;
	return 0;
}