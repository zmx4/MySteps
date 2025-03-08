#include <bits/stdc++.h>
#define endl "\n"
#define ll long long
using namespace std;

bool isPrime(int n)
{
    if(n==1)
        return false;
    for(int i=2;i*i<=n;i++)
    {
        if(n%i==0)
            return false;
    }
    return true;
}

signed main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr),cout.tie(nullptr);

    int n,m;
    cin>>n>>m;
    int i = n+1;
    while(!isPrime(i))
        i++;
    cout<<(i==m?"YES":"NO")<<endl;

	return 0;
}