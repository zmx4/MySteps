#include <bits/stdc++.h>
#define endl "\n"
using ll = long long;
using ull = unsigned long long;
using namespace std;

void solve()
{
    
    int n;
    cin>>n;
    vector<int>a(n);
    for(int i = 0;i < n;i++)
    {
        cin>>a[i];
    }
    int zero = 3,one = 1,two = 2,three = 1,five = 1;
    int ans = 0;
    for(int i = 0;i < n;i++)
    {
        if(zero <= 0 && one <= 0 && two <= 0 && three <= 0 && five<= 0)
        {
            ans = i;
            break;
        }
        if(a[i] == 0)
        {
            zero--;
        }
        else if(a[i] == 1)
        {
            one--;
        }
        else if(a[i] == 2)
        {
        
            two--;
        
        }
        else if(a[i] == 3)
        {
            
            three--;
            
        }
        else if(a[i] == 5)
        {
            five--;
        }
    } 
    if(zero <= 0 && one <= 0 && two <= 0 && three <= 0 && five <= 0)
    {
        if(ans==0)ans=n;
        cout<<ans<<endl;
    }
    else
    {
        cout<<0<<endl;
    }
    return;
    
    
}

signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr),cout.tie(nullptr);
    char readBuffer[1 << 20];
    cin.rdbuf()->pubsetbuf(readBuffer, sizeof(readBuffer));

    int T;cin>>T;
    while(T--)
    {
        solve();
    }
    
    return 0;
}