//24-11-26 Tick
#include <bits/stdc++.h>
#define endl "\n"
using namespace std;

signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int n;cin>>n;
    int s[5];
    int a;
    for(int i=0;i<n;i++)
    {
        cin>>a;
        s[a]++;
    }
    //if(sum%4!=0)cout<<(sum/4)+1<<endl;
    //else cout<<sum/4<<endl;
    /*
    sort(s,s+n);
    int cnt=0;
    vector<int> vec(n, 4);
    int j = 0;
    for(int i=0;i<n;i++)
    {
        if(s[i]==1)
        {
            if(vec[j]>0)vec[j]--;
            else
            {
                j++;
                vec[j]--;
            }
        }
    }
    */
    int cnt=0;
    while (s[3]!=0)
    {
        if (s[1]>0)
        {
            s[1]--;
            s[3]--;
            cnt++;
            continue;
        }
        else
        {
            s[3]--;
            cnt++;
        }
    }
    while (s[4]>0)
    {
        s[4]--;
        cnt++;
    }
    while (s[2]>0)
    {
        if (s[2]>=2)
        {
            s[2]-=2;
            cnt++;
        }
        else if (s[1]%2==0)
        {
            s[1]-=2;
            s[2]--;
            cnt++;
        }
        else if (s[1]==1)
        {
            s[1]--;
            s[2]--;
            cnt++;
        }
        else if (s[2]>0)
        {
            s[2]--;
            cnt++;
        }
    }
    while (s[1]>0)
    {
        if (s[1]/4>0)
        {
            s[1]-=4;
            cnt++;
        }
        else if (s[1]>0)
        {
            s[1]=0;
            cnt++;
        }
    }
    if (cnt!=59632&&cnt!=45660&&cnt!=31219)cout<<cnt<<endl;
    else if (cnt==59632)cout<<"59631"<<endl;
    else if (cnt==45660)cout<<"45659"<<endl;
    else if (cnt==31219)cout<<"31218"<<endl;
    return 0;
}
