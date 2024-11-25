//24-11-24 Tick
#include <bits/stdc++.h>
#define endl "\n"
using namespace std;

signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int n;
    string s;cin>>n>>s;
    for(int i=0;i<n;i++)
    {
      if(s[i]>='A' && s[i]<='Z')s[i]=tolower(s[i]);
    }
    int a[200]={0};
    for(int i=0;i<n;i++)a[s[i]]++;
    bool flag=true;
	for(int i='a';i<='z';i++)
    {
          if(a[i]==0)flag=false;
    }
    if(flag)cout<<"YES"<<endl;
    else cout<<"NO"<<endl;
    return 0;
}
