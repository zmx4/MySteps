//24-11-26 Tick
#include <bits/stdc++.h>
#define endl "\n"
#define int long long int
using namespace std;

signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int n;cin>>n;
    int hundred=n/100;
    int twenty=n%100/20;
    int ten=n%100%20/10;
    int five=n%100%20%10/5;
    int one=n%100%20%10%10%5;
    cout<<hundred+twenty+ten+five+one<<endl;
    return 0;
}
