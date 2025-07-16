#include <bits/stdc++.h>
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
vector<ull> generatePalindromes(ull a);
string to_base(ull num, int base)
{
    if (num == 0)
        return "0";
    string s;
    while (num > 0)
    {
        int d = num % base;
        if (d < 10)
            s.push_back('0' + d);
        else
            s.push_back('A' + (d - 10));
        num /= base;
    }
    reverse(s.begin(), s.end());
    return s;
}
inline void solve()
{
    int a;
    ll n;
    cin >> a >> n;
    vector<ull> v = generatePalindromes(n);
    ll ans = 0;
    for(auto num:v)
    {
        string s = to_base(num,a);
        string rev(s.rbegin(), s.rend());
        if(s==rev)
            ans += num;
    }
    cout << ans << endl;
}

signed main()
{
    cin.tie(nullptr)->ios::sync_with_stdio(false);cout.tie(nullptr);
#if ONLINE_JUDGE
	char readBuffer[1 << 20];
	cin.rdbuf()->pubsetbuf(readBuffer, sizeof(readBuffer));
#endif
	int T = 1;	// cin>>T;
	while(T--)
	{
		solve();
	}
	
	return 0;
}
std::vector<ull> generatePalindromes(ull a)
{
    std::vector<ull> palindromes;
    if (a < 1)
        return palindromes;
    for (ull d = 1; d <= 9 && d <= a; ++d)
    {
        palindromes.push_back(d);
    }

    int maxLen = std::to_string(a).length();
    for (int len = 2; len <= maxLen; ++len)
    {
        bool isOdd = (len % 2 != 0);
        int halfLen = (len + 1) / 2;
        ull start = static_cast<ull>(std::pow(10, halfLen - 1));
        ull end = static_cast<ull>(std::pow(10, halfLen)) - 1;
        for (ull prefix = start; prefix <= end; ++prefix)
        {
            std::string s = std::to_string(prefix);
            std::string rs = s;
            std::reverse(rs.begin(), rs.end());
            std::string palinStr = isOdd
                                       ? s + rs.substr(1)
                                       : s + rs;

            ull palin = std::stoull(palinStr);
            if (palin > a)
            {
                break;
            }
            palindromes.push_back(palin);
        }
    }

    return palindromes;
}