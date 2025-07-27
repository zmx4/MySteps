#include <bits/stdc++.h>
#include <bits/extc++.h>
#define endl "\n"
#define fi first
#define se second
#define pb push_back
#define gcd __gcd
typedef int64_t i64;
typedef int32_t i32;
using ll = long long;using ull = unsigned long long;using LL = long long;using ULL = unsigned long long;
using namespace std;
const int inf = 0x3f3f3f3f,INF = 0x3f3f3f3f;
ll gcd(ll a, ll b){if (b == 0)return a;return gcd(b, a % b);}
ll lcm(ll a, ll b) { return a / gcd(a, b) * b; }
#define int long long
template <typename T>
ostream &operator<<(ostream &os, const vector<T> &v){os << "[";for (auto it = v.begin(); it != v.end(); ++it){if (it != v.begin())os << ", ";os << *it;}return os << "]";}
template <typename T1, typename T2>
ostream &operator<<(ostream &os, const pair<T1, T2> &p) { return os << "(" << p.first << ", " << p.second << ")"; }
#define dbg(...) cerr << "[" << __LINE__ << "] " << #__VA_ARGS__ << " = ", _dbg(__VA_ARGS__), cerr << endl
void _dbg() {}
template <typename T, typename... Args>
void _dbg(T &&arg, Args &&...args){cerr << arg;if (sizeof...(args) > 0)cerr << ", ";_dbg(args...);}
template <typename T, typename N, typename... Args>
void _dbg(T *arr, N n, Args &&...rest){cerr << "[";for (N i = 0; i < n; ++i){if (i != 0)cerr << ", ";cerr << arr[i];}cerr << "]";if (sizeof...(rest) > 0)cerr << ", ";_dbg(rest...);}
const int N = 1e5 + 10, M = 1e5 + 10;
__gnu_pbds::tree<long long, __gnu_pbds::null_type, less<long long>, __gnu_pbds::rb_tree_tag, __gnu_pbds::tree_order_statistics_node_update> tre;
inline void solve()
{
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        int op, k;
        cin >> op >> k;
        if (op == 1)
            tre.insert((k << 20) + i);
        else if (op == 2)
            tre.erase(tre.lower_bound(k << 20));
        else if (op == 3)
            cout << tre.order_of_key(k << 20) + 1 << endl;
        else if (op == 4)
            cout << ((*tre.find_by_order(k - 1)) >> 20) << endl;
        else if (op == 5)
            cout << ((*--tre.lower_bound(k << 20)) >> 20)<<endl;
        else
            cout << ((*tre.upper_bound((k << 20) + n)) >> 20) << endl;
    }
}
/*
rope<int>a;
int main(){
    cin>>n;
    while(n--){
        cin>>op>>x;
        if(op==1) a.insert(lower_bound(a.begin(),a.end(),x)-a.begin(),x);
        if(op==2) a.erase(lower_bound(a.begin(),a.end(),x)-a.begin(),1);
        if(op==3) cout<<lower_bound(a.begin(),a.end(),x)-a.begin()+1<<endl;
        if(op==4) cout<<a[x-1]<<endl;
        if(op==5) cout<<a[lower_bound(a.begin(),a.end(),x)-a.begin()-1]<<endl;
        if(op==6) cout<<a[upper_bound(a.begin(),a.end(),x)-a.begin()]<<endl;
    }
}
*/
signed main()
{
    cin.tie(nullptr)->ios::sync_with_stdio(false);cout.tie(nullptr);
#if ONLINE_JUDGE
	char readBuffer[1 << 20];
	cin.rdbuf()->pubsetbuf(readBuffer, sizeof(readBuffer));
#endif
	int T = 1;	//cin>>T;
	while(T--)
	{
		solve();
	}
	
	return 0;
}
