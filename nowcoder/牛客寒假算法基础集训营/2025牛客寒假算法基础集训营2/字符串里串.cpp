#include <bits/stdc++.h>

using namespace std;

typedef long long ll;


int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr), cout.tie(nullptr);

	int n;
	cin >> n;
	string s;
	cin >> s;
 	s=" "+s;
	int ans = 0;
 	set<int>st;
	for (int i = n; i >= 2;i--)
	{
   		if(st.count(s[i])) ans = max(ans, i);
   		st.insert(s[i]);
	}
 	st = set<int>();
 	for(int i = 1;i <= n - 1;i++)
 	{
   		if(st.count(s[i])) ans = max(ans, n - i + 1);
        st.insert(s[i]);
 	}
 	cout<<ans<<endl;
	return 0;
}