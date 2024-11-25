//24-11-25 Tick
#include <bits/stdc++.h>
#define endl "\n"
using namespace std;

signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int n;cin>>n;
    int a[n+1]={0};
    int temp;
    cin>>temp;
	int s;
	while(temp--)
	{
		cin>>s;a[s]=1;
	}
	cin>>temp;
	while(temp--)
	{
		cin>>s;a[s]=1;
	}
    bool flag=true;
	for(int i=1;i<=n;i++)
    {
          if(a[i]==0)flag=false;
    }
	//cout<<a[4]<<endl;
    if(flag)cout<<"I become the guy."<<endl;
    else cout<<"Oh, my keyboard!"<<endl;
    return 0;
}
