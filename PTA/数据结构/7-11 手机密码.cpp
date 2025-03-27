#include <bits/stdc++.h>
#define endl "\n"
using ll = long long;
using ull = unsigned long long;
using namespace std;
vector<string> ans;
vector<int> v1, v2(10);
signed main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr),cout.tie(nullptr);

	string s;
	cin >> s;
	
	for (int i = 0;i < 10;++i)
	{
		if (s[i] == 'x')continue;
		else if (s[i] == 'o')v2[i] = 1,v1.push_back(i);
		else v2[i] = 1;
	}
	
	if(v1.size() == 0||v1.size() > 4)
		return 0;
	for(int i = 1;i < 10000;++i)
	{
		stringstream ss;
		ss << setw(4) << setfill('0') << i;
		string pwd = ss.str();
		bool legal = true;

		for(char c : pwd)
			if(v2[c - '0'] == 0)
				legal = false;
		if(!legal)continue;
		else
		{
			for(int num:v1)
				if(pwd.find(to_string(num)) == string::npos)
					legal = false;
		}
		if(legal)
			ans.push_back(pwd);
	}
	if(ans.size() == 0)return 0;
	else
	{
		for(auto i:ans)
			cout << i << endl;
	}
		return 0;
}