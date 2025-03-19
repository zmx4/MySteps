#include <bits/stdc++.h>
using namespace std;
#define endl "\n"
int a[51]={0},b[51]={0};
int main()
{
    int T;cin>>T;
    while(T--)
    {
        int n;cin>>n;
        for (int i = 1; i <= n; i++)
        {
            cin>>a[51];
        }
        int j=0;
        sort(begin(a),end(a));
        for(int i=1;i<n;i++)
        {
            if(a[i]!=a[i-1])
            {
                b[j]=a[i];
                j++;
            }
        }
        
    }
}