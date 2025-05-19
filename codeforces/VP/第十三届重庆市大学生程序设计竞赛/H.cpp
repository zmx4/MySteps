#include<bits/stdc++.h>
//#include<bits/extc++.h>
#define fi first
#define se second
#define pb push_back
//#define endl "\n"
#define int long long
using namespace std;
//using namespace __gnu_pbds;
typedef long long LL;
typedef pair<int, int> PII;
typedef unsigned long long ULL;
typedef __int128_t int128;
//typedef tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> order_set;
template<typename T>
ostream& operator<<(ostream& os, const vector<T>& v) {os << "[";for (auto it = v.begin(); it != v.end(); ++it) {if (it != v.begin()) os << ", ";os << *it;}return os << "]";}
template<typename T1, typename T2>
ostream& operator<<(ostream& os, const pair<T1, T2>& p) {return os << "(" << p.first << ", " << p.second << ")";}
#define dbg(...) cerr << "[" << __LINE__ << "] " << #__VA_ARGS__ << " = ", _dbg(__VA_ARGS__), cerr << endl
void _dbg() {} 
template<typename T, typename... Args>
void _dbg(T&& arg, Args&&... args) {cerr << arg;if (sizeof...(args) > 0) cerr << ", ";_dbg(args...);}
template<typename T, typename N, typename... Args>
void _dbg(T* arr, N n, Args&&... rest) {cerr << "[";for (N i = 0; i < n; ++i) {if (i != 0) cerr << ", ";cerr << arr[i];}cerr << "]";if (sizeof...(rest) > 0) cerr << ", ";_dbg(rest...);}
LL qpow(LL a, LL b, LL m) {LL res = 1; while (b) { if (b & 1) res = (res * a) % m;a = (a * a) % m; b >>= 1; }return res; }
LL lowbit(LL x) { return x & -x; }
LL gcd(LL a, LL b) { return b == 0 ? a : gcd(b, a % b); }
LL lcm(LL a,LL b){ return a * b / gcd(a , b); }
LL exgcd(LL a, LL b, LL& x, LL& y) { if (!b) { x = 1, y = 0; return a; }LL d = exgcd(b, a % b, y, x); y -= a / b * x; return d; }
const double PI = acos(-1);
const int Mod = 998244353, mod = 1e9 + 7, INF = 0x3f3f3f3f, INFF = 0x3f3f3f3f3f3f3f3f;//51971
const int N = 3e5 + 10, M = 1e6 + 10, MN = 3e3 + 10;
int n,m,k;
int a[N],b[N],c[N],id[N];
string s;
void solve(){
    cin>>n;
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    for(int i=0;i<n;i++){
        cin>>b[i];
        id[b[i]]=i;
    }
    for(int i=0;i<n;i++){
        cin>>c[i];
    }
    bool ok=1;
    int lst=-1;
    for(int i=0;i<n;i++){
        if(c[i]==1){
            if(lst==-1){
                lst=id[a[i]];
                //dbg(lst);
            }
            else if(lst>id[a[i]]){
                ok=0;
                break;
            }
            lst=id[a[i]];
        }
    }
    cout<<(ok?"Yes":"No")<<endl;
}
signed main()
{
    cin.tie(0),cout.tie(0);ios::sync_with_stdio(false);
    int oo = 1; cin >> oo;
    while (oo--) {
        solve();
    }
    return 0;
}