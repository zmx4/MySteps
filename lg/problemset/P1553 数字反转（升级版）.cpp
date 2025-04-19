#include <bits/stdc++.h>
#define endl "\n"
using ll = long long;
using ull = unsigned long long;
using namespace std;
const int inf = 0x3f3f3f3f;
string remove_zero(const string &s)
{
	int i = 0;
	while (i < s.size() && s[i] == '0')
	{
		i++;
	}
	string ret = s.substr(i);
	return ret.empty() ? "0" : ret;
}

string remove_zero_end(const string &s)
{
	int i = s.size() - 1;
	while (i >= 0 && s[i] == '0')
	{
		i--;
	}
	string ret = s.substr(0, i + 1);
	return ret.empty() ? "0" : ret;
}
signed main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr),cout.tie(nullptr);

	string num;
	cin >> num;
	bool isprecent = (num[num.size() - 1] == '%');
	if (isprecent) num.pop_back();
	bool isxiaoshu = (num.find('.') != string::npos);
	bool isfeng = (num.find('/') != string::npos);
	if(!isxiaoshu && !isfeng && !isprecent) {
		reverse(num.begin(), num.end());
		num = remove_zero(num); // 赋值回来
		cout << num << endl;
	}
	else if(isprecent)
	{
		reverse(num.begin(), num.end());
		num = remove_zero(num);
		cout << num <<"%"<< endl;
	}
	else if(isfeng)
	{
		int pos = num.find('/');
		string numerator = num.substr(0, pos);
		string denominator = num.substr(pos + 1);
		reverse(numerator.begin(), numerator.end());
		reverse(denominator.begin(), denominator.end());
		numerator = remove_zero(numerator);
		denominator = remove_zero_end(denominator);
		denominator = remove_zero(denominator);
		if (numerator == "0" && denominator == "0")
		{
			cout << "0" << endl;
			return 0;
		}
		cout << numerator << "/" << denominator << endl;
	}
	else if(isxiaoshu)
	{
		auto pos = num.find('.');
		string integerPart = num.substr(0, pos);
		string fractionalPart = num.substr(pos + 1);
		reverse(integerPart.begin(), integerPart.end());
		reverse(fractionalPart.begin(), fractionalPart.end());
		integerPart = remove_zero(integerPart);
		fractionalPart = remove_zero_end(fractionalPart);
		fractionalPart = remove_zero(fractionalPart);
		cout << integerPart << "." << fractionalPart << endl;
	}

	return 0;
}