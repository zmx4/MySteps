#include <bits/stdc++.h>
#define endl "\n"
using ll = long long;
using ull = unsigned long long;
using namespace std;
const int inf = 0x3f3f3f3f;
int n, m, smax;

signed main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr),cout.tie(nullptr);
	/*
		cin >> n >> m >> smax;
		stack<char> s1,s2,s3;
		string str1, str2, str3;
		cin >> str1 >> str2 >> str3;
		reverse(str1.begin(), str1.end());
		reverse(str2.begin(), str2.end());
		reverse(str3.begin(), str3.end());
		for (int i = 0; i < m; i++)
		{
			s1.push(str1[i]);
			s2.push(str2[i]);
			s3.push(str3[i]);
		}
		int op;
		stack<char> stk;
		vector<char> ans;
		while(cin>>op)
		{
			if(op==-1)
				break;
			else if(op == 0)
			{
				if(!stk.empty())
				{
					ans.push_back(stk.top());
					stk.pop();
				}
			}
			else if(op == 1)
			{
				if(s1.empty())
					continue;
				if(stk.size()<smax)
				{
					stk.push(s1.top());
					s1.pop();
				}
				else
				{
					ans.push_back(stk.top());
					stk.pop();
					stk.push(s1.top());
				}
			}
			else if(op == 2)
			{
				if(s2.empty())
					continue;
				if(stk.size()<smax)
				{
					stk.push(s2.top());
					s2.pop();
				}
				else
				{
					ans.push_back(stk.top());
					stk.pop();
					stk.push(s2.top());
				}
			}
			else if(op == 3)
			{
				if(s3.empty())
					continue;
				if(stk.size()<smax)
				{
					stk.push(s3.top());
					s3.pop();
				}
				else
				{
					ans.push_back(stk.top());
					stk.pop();
					stk.push(s3.top());
				}

			}
		}
		for (int i = 0; i < ans.size(); i++)
		{
			cout << ans[i];
		}
		cout << endl;
	*/
	cin >> n >> m >> smax;
	queue<char> q[110];
	string str[110];
	// for (int i = 1; i <= n;i++)
	// {
		// cin >> str[i];
		// reverse(str[i].begin(), str[i].end());
	// }
	for (int i = 1; i <= n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			char c;
			cin >> c;
			q[i].push(c);
		}
	}
	int op;
	stack<char> stk;
	vector<char> ans;
	while(cin>>op)
	{
		if(op == -1)
			break;
		if(op == 0)
		{
			if(!stk.empty())
			{
				ans.push_back(stk.top());
				stk.pop();
			}
		}
		else
		{
			if (stk.size() < smax && !q[op].empty())
			{
				stk.push(q[op].front());
				q[op].pop();
			}
			else if (stk.size() == smax && !q[op].empty())
			{
				ans.push_back(stk.top());
				stk.pop();
				stk.push(q[op].front());
				q[op].pop();
			}
		}
	}
	for (int i = 0; i < ans.size(); i++)
	{
		cout << ans[i];
	}
	return 0;
}