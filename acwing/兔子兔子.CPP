//24-11-24 Tick
#include <bits/stdc++.h>
#define endl "\n"
using namespace std;

typedef unsigned long long ull;
constexpr int N = 1000010,base = 131;
ull h[N],p[N];
ull getHash(const ull l, const ull r)
{
	return h[r]- h[l-1] * p[r - l + 1];
}
char s[N];
signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

	p[0]=1;
	scanf("%s",s + 1);
    //string s;cin>>s;
    //string a = "0"+s;
	h[0]=0;
	const ull n = strlen(s + 1);
    for(int i=1;i<=n;i++)
    {
      h[i] = h[i-1]*base + s[i] - 'a' + 1;
      p[i] = p[i-1]*base;
    	//cout<<s[i]<<" ";
    }

    //for(int i=1;i<=s.length();i++)cout<<h[i]<<endl;
	ull m;cin>>m;
	while(m--)
	{
		ull l1,l2,r1,r2;cin>>l1>>r1>>l2>>r2;
		//cout<<getHash(l1,r1)<<" "<<getHash(l2,r2)<<endl;
		if(getHash(l1,r1)==getHash(l2,r2))cout<<"YES"<<endl;
		else cout<<"NO"<<endl;
	}
    return 0;
}
