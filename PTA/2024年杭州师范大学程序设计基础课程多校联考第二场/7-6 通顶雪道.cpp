#include<bits/stdc++.h>
using namespace std;

signed main()
{
    int n;cin>>n;
    int a[1010]={0};
    for(int i = 1;i <= n;i++)
    {
        cin>>a[i];
        //cout<<a[i]<<endl;
    }
    int t;cin>>t;
    int l,r;
    int j = 1;
    while(t--)
    {
        cin>>l>>r;
        for (int i = l; i <= r; ++i) 
        {
            if (i <= (l + r) / 2) 
            {
                a[i] += (i - l + 1);
            } 
            else 
            {
                a[i] += (r - i + 1);
            }
        }
        /*
        for(int i = l;i < r;i++)
        {
            
            if(i<(l+r)/2)
            {
                a[i]+=j;
                j++;
            }
            else
            {
                a[i]+=j;
                j--;
            }
            //cout<<a[i]<<" "<<j<<endl;
        }
        */
    }
    for(int i = 1;i <= n;i++)
    {
        cout<<a[i];
    }
}