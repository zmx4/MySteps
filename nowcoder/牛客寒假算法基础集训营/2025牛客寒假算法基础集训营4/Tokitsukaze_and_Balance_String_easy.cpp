#include <bits/stdc++.h>
#define endl "\n"
#define ll long long
using namespace std;
const int MOD = 1000000007;
vector<string> init(vector<string> ss)
{
    if(ss[0].find('?')==string::npos)
    {
        return ss;
    }
    vector<string> res;
    for(auto s:ss)
    {
        string t = s;
        int n = s.size();
        for(int i=0;i<n;i++)
        {
            if(s[i]=='?')
            {
                t[i] = '0';
                res.push_back(t);
                t[i] = '1';
                res.push_back(t);
                break;
            }
        }
    }
    return init(res);
}

void solve()
{
    int n;cin>>n;
    string str;cin>>str;
    vector<string> a;
    a.push_back(str);
    a = init(a);
    /*
    for(auto s:a)
    {
        cout<<s<<endl;
    }
    */
    ll ans = 0;
    for(auto s:a)
    {
        int cnt = 0;
        for(int i=0;i<n;i++)
        {
            string temp = s;
            int cnt01 = 0,cnt10 = 0;
            if(temp[i]=='0') temp[i] = '1';
            else if(temp[i]=='1') temp[i] = '0';
            for(int j=0;j<n-1;j++)
            {
                if(temp[j]=='0' && temp[j+1]=='1') cnt01++;
                if(temp[j]=='1' && temp[j+1]=='0') cnt10++;
            }
            if(cnt01==cnt10) cnt++;
        }
        cnt %= MOD;
        ans += cnt;
        ans %= MOD;
    }
    cout<<ans<<endl;
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