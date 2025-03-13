#include <iostream>
#include <string>
using namespace std;
bool judgeIsDstr(const string &a)
{
	int LengthA = a.length();
	for (int i = 0; i < LengthA / 2; i++)
	{
		if (a[i] != a[LengthA - i - 1])
			return false;
	}
	return true;
}
int main()
{
	string a;
	getline(cin, a);
	int maxlength = 0;
	for (int i = 0; i < a.length(); i++)
	{
		for (int j = a.length() - 1; j >= i; j--)
		{
			if (a[j] == a[i])
			{
				string suba = a.substr(i, j - i + 1);
				if (judgeIsDstr(suba))
				{
					int len = suba.length();
					maxlength = max(maxlength, len);
				}
			}
		}
	}
	cout << maxlength;
}