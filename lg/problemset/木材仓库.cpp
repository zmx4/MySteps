#include <bits/stdc++.h>
#define endl '\n'
#define fi first
#define se second
#define pb push_back
#define gcd __gcd
typedef int64_t i64;
typedef int32_t i32;
using ll = long long;using ull = unsigned long long;using LL = long long;using ULL = unsigned long long;
using namespace std;
const int inf = 0x3f3f3f3f,INF = 0x3f3f3f3f;
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
inline void solve()
{
	set<int> s;
    vector<int> v;
    int n;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        int op, x;
        cin >> op >> x;
        if (op == 1)
        {
            if(s.count(x) == 0)
            {
                s.insert(x);
            }
            else
            {
                cout<<"Already Exist"<<endl;
            }
        }
        else
        {
            auto it = s.lower_bound(x);
            // 直接命中
            if (it != s.end() && *it == x)
            {
                cout << x << endl;
                s.erase(it);
            }
            else
            {
                if(s.empty())
                {
                    cout << "Empty" << endl;
                    continue;
                }
                // 候选：it 指向大于 x 的第一个；it2 指向小于 x 的最大
                long long diff1 = LLONG_MAX, diff2 = LLONG_MAX;
                int c1 = 0, c2 = 0;
                if (it != s.end())
                {
                    diff1 = (long long)(*it) - x;
                    c1 = *it;
                }
                if (it != s.begin())
                {
                    auto it2 = prev(it);
                    diff2 = (long long)x - *it2;
                    c2 = *it2;
                }
                // 取距离更小；若相等则取更小者(c2)
                int cand = (diff1 < diff2 ? c1 : c2);
                cout << cand << endl;
                s.erase(cand);
            }
        }
    }
    
	
	
	
	
}

signed main()
{
    cin.tie(nullptr)->ios::sync_with_stdio(false);cout.tie(nullptr);
#if ONLINE_JUDGE
	char readBuffer[1 << 20];
	cin.rdbuf()->pubsetbuf(readBuffer, sizeof(readBuffer));
#endif
	int T = 1;	//n>>T;
	while(T--)
	{
		solve();
	}
	
	return 0;
}