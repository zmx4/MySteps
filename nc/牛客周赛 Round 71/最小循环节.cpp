#include <bits/stdc++.h>
using namespace std;

signed main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);cout.tie(nullptr);
	/*
	a f   avfdb     bx     x
	avfdbxavfdbxavfdbxavfdbx
	*/
	string s;
	cin >> s;

	unordered_set<char> uniquesubstr(s.begin(), s.end());
	cout << uniquesubstr.size();

	return 0;
}