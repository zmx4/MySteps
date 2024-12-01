#include<bits/stdc++.h>
using namespace std;

int judge(int a[],const int &n)
{
    /*
    int i = 1,j=a[i];
    while(j[])
    */
    int cnt = 0;
    for(int i = 1;i <= n;i++)
    {
        if(a[i]==i)
        {
            a[i]=0;
            cnt++;
            continue;
        }
        if(a[i]==0)continue;
        int k = a[i];
        while(k!=i)
        {
            int temp = k;
            k = a[k];
            a[temp]=0;
        }
        cnt++;
    }
    return cnt;
}

int main()
{
    int T;cin>>T;
    while(T--)
    {
        int n;cin>>n;
        int a[n+10];
        for(int i = 1;i <= n;i++)cin>>a[i];
        if(n==1)cout<<1<<endl;
        else
        {
            cout<<judge(a,n)<<endl;
        }
    }
}