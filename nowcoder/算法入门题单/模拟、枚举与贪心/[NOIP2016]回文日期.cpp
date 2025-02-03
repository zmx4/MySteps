#include <bits/stdc++.h>
#define endl "\n"
#define ll long long
using namespace std;

//int p[13]={0,31,28,31,30,31,30,31,31,30,31,30,31},r[13]={0,31,29,31,30,31,30,31,31,30,31,30,31};

vector<int> v1 = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31}, v2 = {0, 31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

bool isPalindrome(string_view str)
{
	int i = 0, j = str.size() - 1;
	while (i < j)
	{
		if (str[i] != str[j])
			return false;
		i++;
		j--;
	}
	return true;
}

bool isLeapYear(const int &year)
{
	if (year % 4 == 0 && year % 100 != 0 || year % 400 == 0)
		return true;
	else
		return false;
}

signed main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr),cout.tie(nullptr);

	string date1, date2;
	cin>>date1>>date2;
	int y1 = stoi(date1.substr(0, 4)), m1 = stoi(date1.substr(4, 2)), d1 = stoi(date1.substr(6, 2));
	int y2 = stoi(date2.substr(0, 4)), m2 = stoi(date2.substr(4, 2)), d2 = stoi(date2.substr(6, 2));
	int ans = 0;
	vector<int> str1;
	for(int i = y1; i <= y2; i++)
	{
		if(isLeapYear(i))
		{
			for (int j = 1;j <= 12;j++)
			{
				for (int k = 1;k <= v2[j];k++)
				{
					if(isPalindrome(to_string(i) + (j < 10 ? "0" : "") + to_string(j) + (k < 10 ? "0" : "") + to_string(k)))
						str1.push_back(i * 10000 + j * 100 + k);
				}
			}
		}
		else
		{
			for(int j = 1;j <= 12;j++)
			{
				for(int k = 1;k <= v1[j];k++)
				{
					if(isPalindrome(to_string(i) + (j < 10 ? "0" : "") + to_string(j) + (k < 10 ? "0" : "") + to_string(k)))
						str1.push_back(i * 10000 + j * 100 + k);
				}
			}
		}
	}
	for(int i : str1)
	{
		if(i >= y1 * 10000 + m1 * 100 + d1 && i <= y2 * 10000 + m2 * 100 + d2)
			ans++;
	}
	cout<<ans<<endl;
	return 0;
}