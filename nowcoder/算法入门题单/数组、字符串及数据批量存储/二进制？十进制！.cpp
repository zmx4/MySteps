#include <bits/stdc++.h>
#define endl "\n"
#define ll long long
using namespace std;

signed main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr),cout.tie(nullptr);

	ll a, b;
	cin>>a>>b;
	bitset<32768> A(a), B(b);
	string s1 = A.to_string(), s2 = B.to_string();
	ll num1=stoll(s1), num2=stoll(s2);
	cout<<num1+num2<<endl;
	return 0;
}