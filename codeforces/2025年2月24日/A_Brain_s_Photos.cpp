#include <bits/stdc++.h>
#define endl "\n"
#define ll long long
using namespace std;

signed main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr),cout.tie(nullptr);

    int n,m;cin>>n>>m;
    bool flag=false;
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<m;j++)
        {
            char c;cin>>c;
            if(c=='C'||c=='M'||c=='Y')
            {
                flag=true;
            }
        }
    }
    if(flag)
    {
        cout<<"#Color"<<endl;
    }
    else
    {
        cout<<"#Black&White"<<endl;
    }

	return 0;
}