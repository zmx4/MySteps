#include <bits/stdc++.h>
#define endl "\n"
#define ll long long
using namespace std;

const string tar = "CHICKEN";

void solve()
{
    int n;
    string s;
    cin >> n >> s;
    /*
    int cnt = 0;
    int nt = 0;
    map<char,int> mp,ex;
    for(int i = 0;i<n;i++)
    {
        if(s[i]==tar[nt])
        {
            nt++;
        }
        if(s[i]!='C'&&s[i]!='H'&&s[i]!='I'&&s[i]!='K'&&s[i]!='E'&&s[i]!='N')
        {
            ex[s[i]]++;
        }
        else
        {
            if(s[i]=='C'&&mp['C']<=2)
            {
                mp[s[i]]++;
            }
            else if(s[i]=='H'&&mp['H']<1)
            {
                mp[s[i]]++;
            }
            else if(s[i]=='I'&&mp['I']<1)
            {
                mp[s[i]]++;
            }
            else if(s[i]=='K'&&mp['K']<1)
            {
                mp[s[i]]++;
            }
            else if(s[i]=='E'&&mp['E']<1)
            {
                mp[s[i]]++;
            }
            else if(s[i]=='N'&&mp['N']<1)
            {
                mp[s[i]]++;
            }
            else
            {
                ex[s[i]]++;
            }
        }
    }
    for(int i = 'A';i <= 'Z';i++)
    {
        if(ex[(char)i]%2!=1&&ex[(char)i]!=0)
        {
            cout<<"NO"<<endl;
            return;
        }
        else
        {
            cnt++;
        }
    }
    if((n-7)%2==1)
    {
        cout<<"NO"<<endl;
        return;
    }
    if(nt==7)
    {
        cout<<"YES"<<endl;
    }
    else
    {
        cout<<"NO"<<endl;
    }
    */
    if(n < 7)
    {
        cout << "NO" << endl;
        return;
    }
    
    map<char, int> mp;
    for(auto c : tar)
    {
        mp[c]++;
    }
    
    vector<bool> used(n, false);
    int nt = 0;
    /*
    for(int i = 0;i < s.size();i++)
    {
        if(s[i]==tar[nt])
        {
            nt++;
        }
        else
        {
            ex[s[i]]++;
            exsum++;
        }
    }
    */
    for (int i = 0; i < n && nt < tar.size(); i++)
    {
        if (s[i] == tar[nt])
        {
            used[i] = true;
            nt++;
        }
    }
    if(nt != 7)
    {
        cout << "NO" << endl;
        return;
    }
    
    ll exsum = 0;
    map<char, int> ex;
    for (int i = 0; i < n; i++)
    {
        if (!used[i])
        {
            ex[s[i]]++;
            exsum++;
        }
    }

    if(exsum % 2 == 1)
    {
        cout << "NO" << endl;
        return;
    }
    
    for (auto &p : ex)
    {
        if (p.second > exsum / 2)
        {
            cout << "NO" << endl;
            return;
        }
    }
    
    cout << "YES" << endl;
}

signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr), cout.tie(nullptr);
    char readBuffer[1 << 20];
    cin.rdbuf()->pubsetbuf(readBuffer, sizeof(readBuffer));

    int T;
    cin >> T;
    while(T--)
    {
        solve();
    }
    
    return 0;
}