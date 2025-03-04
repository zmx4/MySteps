#include <bits/stdc++.h>
#define endl "\n"
#define ll long long
using namespace std;

signed main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr),cout.tie(nullptr);

    int m,s;
    cin>>m>>s;
    if(s==0)
    {
        cout<<(m==1?"0 0":"-1 -1")<<endl;
        return 0;
    }
    if(s>9*m)
    {
        cout<<"-1 -1"<<endl;
        return 0;
    }
    string a,b;
    for(int i=0;i<m;i++)
    {
        int x = min(9,s);
        b += (char)(x+'0');
        s -= x;
    }
    a = b;
    reverse(a.begin(),a.end());
    if(a[0]=='0')
    {
        for(int i=0;i<a.size();i++)
        {
            if(a[i]!='0')
            {
                a[i]--;
                a[0]++;
                break;
            }
        }
    }
    cout<<a<<" "<<b<<endl;

	return 0;
}