#include <bits/stdc++.h>
#define endl "\n"
#define ll long long
using namespace std;

void solve()
{
    int n;
    cin>>n;
    string s;
    cin>>s;
    deque<char> st;
    stack<char> st1;
    int ans=0;
    for(int i=0;i<n;i++)
    {
        st.push_back(s[i]);
    }
    int l=0,r=1;
    while(!st.empty())
    {
        if(st1.empty())
        {
            st1.push(st.front());
            st.pop_front();
        }
        else
        {
            if(st1.top()=='(' && st.front()==')')
            {
                st1.pop();
                st.pop_front();
            }
            else
            {
                st1.push(st.front());
                st.pop_front();
            }
        }
        
    }
    if(st.empty())
    {
        if(st1.size()%2==0)
        {
            ans+=st1.size()/2;
        }
        else
        {
            ans+=st1.size()/2+1;
        }
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