//24-12-2 Tick
#include <bits/stdc++.h>
#define endl "\n"
using namespace std;
int a[100];
int n,k;
void solve(int arr[])
{

}

signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);cout.tie(nullptr);

    cin>>n>>k;

    for(int i=1;i<=n;i++)a[i]=1;
    for(int i = 1;i<=pow(k,n);i++)solve(a);

    return 0;
}

