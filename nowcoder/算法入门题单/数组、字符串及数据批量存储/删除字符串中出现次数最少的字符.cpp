#include <climits>
#include <iostream>
#include <map>
using namespace std;

int main()
{
	string s;
	cin >> s;
	map<char, int> cnt;
	for (auto c : s)
	{
		cnt[c]++;
	}
	int mincnt = INT_MAX;
	for (auto p : cnt)
	{
		if (p.second < mincnt)
		{
			mincnt = p.second;
		}
	}
	for (auto c : s)
	{
		if(cnt[c] != mincnt)
		{
			cout << c;
		}
	}
}
// 64 位输出请用 printf("%lld")