//24-12-2 Tick
#include <bits/stdc++.h>
#define endl "\n"
using namespace std;
int a[100];
int n,k;
void printa()
{
    for(int i=1;i<=n;i++)
    {
        cout<<a[i];
        if(i!=n)cout<<" ";
    }
    cout<<endl;
}
void solve(int arr[])
{
    bool carry = false;
    if (arr[n]<k)
    {
        arr[n]++;
        printa();
        return;
    }
    for(int i=n;i>=1;i--)
    {
        if(arr[i]==k)
        {
            arr[i]=1;
            carry=true;
        }
        else if(arr[i]<k)
        {
            arr[i]++;
            carry=false;
            break;
        }
    }
}


signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);cout.tie(nullptr);

    cin>>n>>k;

    for(int i=1;i<=n;i++)a[i]=1;
    for(int i = 1;i<=n;i++)cout<<a[i]<<" ";
    cout<<endl;
    for(int i = 1;i<=pow(k,n);i++)solve(a);

    return 0;
}

