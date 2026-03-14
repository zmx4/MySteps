#include <bits/stdc++.h>
using namespace std;
int main()
{
	string a, b;
	getline(cin, a);
	getline(cin, b);
	unordered_set<char> rm;
	for(auto c:b)
	{
		rm.insert(c);
	}
	string ans = "";
	for(auto c:a)
	{
		if(!rm.count(c))
			ans.push_back(c);
	}
	cout << ans << endl;
}