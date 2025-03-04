#include <bits/stdc++.h>
#define endl "\n"
#define ll long long
using namespace std;

signed main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr),cout.tie(nullptr);

    int n,m;
    cin>>n>>m;
    if(n<m)
    {
        cout<<n<<endl;
    }
    else
    {
        int ans = 0;
        int cnt1 = n,cnt2 = m;
        while(cnt1--)
        {
            ans++;
            cnt2--;
            if(cnt2==0)
            {
                cnt2 = m;
                cnt1++;
            }
        }
        cout<<ans<<endl;
    }

	return 0;
}