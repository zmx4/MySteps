#include <bits/stdc++.h>
#define endl "\n"
using ll = long long;
using ull = unsigned long long;
using namespace std;
const int inf = 0x3f3f3f3f;

signed main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr),cout.tie(nullptr);

	ll time, hh, mm, ss;
	cin >> time;
	time /= 1000;
	hh = (time % 86400)/(60*60);
	mm = time % (60*60) / 60;
	ss = time % 60;
	cout << format("{:02d}:{:02d}:{:02d}",hh,mm,ss);
	return 0;
}