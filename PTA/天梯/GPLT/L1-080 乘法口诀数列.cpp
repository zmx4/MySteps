#include <bits/stdc++.h>
#define endl "\n"
using ll = long long;
using namespace std;
queue<int> q;
vector<int> ans;
int add(int a, int b)
{
	int product = a * b;
	string s = to_string(product);
	int cnt = s.size();
	for (char c : s)
	{
		int d = c - '0';
		ans.push_back(d);
	}
	//reverse(s.begin(), s.end());
	for (char c : s)
	{
		q.push(c - '0');
	}
	return cnt;
}
void test()
{
	// for(int i=0;i<ans.size();i++)
	// {
		// cout<<ans[i]<<" ";
	// }
	// cout << endl;
	queue<int> temp=q;

	while(!temp.empty())
	{
		cout<<temp.front()<<" ";
		temp.pop();
	}
	cout<<endl;
}
signed main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr),cout.tie(nullptr);

	int a1,a2,n;
	cin>>a1>>a2>>n;
	
	q.push(a1),q.push(a2);
	ans.push_back(a1),ans.push_back(a2);
	int cnt=2;
	while(cnt<n)
	{
		//test();
		int a=q.front();
		q.pop();
		int b=q.front();
		// q.pop();
		// q.push(b);
		cnt+=add(a,b);
		
		
	}
	for (int i = 0;i < n;i++)
	{
		cout<<ans[i];
		if(i!=n-1)cout<<" ";
	}
		return 0;
}