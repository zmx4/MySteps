#include <bits/stdc++.h>
using namespace std;
int main()
{
    ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
    int qwe;cin>>qwe;
    while(qwe--)
    {
        int n, m;
		cin >> n >> m;
		vector<int> a(n + 1); // 类似于开一个 a[n + 1] 的数组
        vector<int> b(n + 2);
        vector<int> cnt(m + 1);
		for (int i = 1; i <= n; i++) 
        {
			cin >> a[i];
		}
		
        for (int i = n; i > 0; i--)
        {
            cnt[a[i]]+=i;
            //cout<<a[i]<<" "<<cnt[a[i]]<<endl;
        } 

		for (int i = 1; i <= m; i++) 
        {
			cout << cnt[i] << " \n"[i == m];
		}
   	}
}