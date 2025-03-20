#include <bits/stdc++.h>
#define endl "\n"
using ll = long long;
using namespace std;

signed main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr),cout.tie(nullptr);

	int n, m;
	cin >> n >> m;
	vector<int> a(m);
	for(auto &i:a)
		cin >> i;
	if(m==1){
		cout << a[0] << endl;
		return 0;
	}
	int sum = accumulate(a.begin(), a.end(),0);
	sum -= n * (m-1);
	if(sum>0)cout << sum << endl;
	else
		cout << 0 << endl;

	return 0;
}