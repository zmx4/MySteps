#include <bits/stdc++.h>
#define endl "\n"
using ll = long long;
using ull = unsigned long long;
using LL = long long;
using namespace std;
const int inf = 0x3f3f3f3f;
const int N = 1e5+10;

signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr),cout.tie(nullptr);


    int n,m;
    cin >> n >> m;
    int minn = min(n,m);
    cout << minn << endl;
    n = minn;
    if(n > 0 && n <= 20)cout<<"XianHua"<<endl;
    else if(n <= 40)cout<<"XiangXun"<<endl;
    else if(n <= 60)cout<<"BaoWenBei"<<endl;
    else if(n <= 200)cout<<"HunShaZhao"<<endl;







    return 0;
}