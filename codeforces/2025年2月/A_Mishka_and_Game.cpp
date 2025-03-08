#include <bits/stdc++.h>
#define endl "\n"
#define ll long long
using namespace std;

signed main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr),cout.tie(nullptr);

    int n;
    cin >> n;
    int msk = 0,chi = 0;
    while(n--)
    {
        int m,c;
        cin >> m >> c;
        if(m > c)msk++;
        else if(m < c)chi++;
    }
    if(msk > chi)cout << "Mishka";
    else if(msk < chi)cout << "Chris";
    else cout << "Friendship is magic!^^";
	return 0;
}