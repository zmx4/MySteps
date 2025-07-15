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
	map<string, int> mp;
    mp["one"] = 1;
    mp["two"] = 2;
    mp["three"] = 3;
    mp["four"] = 4;
    mp["five"] = 5;
    mp["six"] = 6;
    mp["seven"] = 7;
    mp["eight"] = 8;
    mp["nine"] = 9;
    mp["ten"] = 10;
    mp["eleven"] = 11;
    mp["twelve"] = 12;
    mp["thirteen"] = 13;
    mp["fourteen"] = 14;
    mp["fifteen"] = 15;
    mp["sixteen"] = 16;
    mp["seventeen"] = 17;
    mp["eighteen"] = 18;
    mp["nineteen"] = 19;
    mp["twenty"] = 20;
    mp["a"] = 1;
    mp["both"] = 2;
    mp["another"] = 1;
    mp["first"] = 1;
    mp["second"] = 2;
    mp["third"] = 3;
    string word;
    vector<int> num;
    for (int i = 0; i < 6; i++)
    {
        cin >> word;
        transform(word.begin(), word.end(), word.begin(), ::tolower); // 大小写转换
        if (mp.count(word))
        {
            num.push_back((mp[word] * mp[word]) % 100);
        }
    }
    if (num.empty())
    {
        cout << 0;
        exit(0);
    }

    sort(num.begin(), num.end()); // 排序贪心

    string result;
    for (int i : num)
    {
        if (i < 10 && !result.empty())
            result += "0"; // 加先导零
        result += to_string(i);
    }
    unsigned long long No0 = result.find_first_not_of('0');
    if (No0 != string::npos)
        result = result.substr(No0);
    else
        result = "0";
    cout << result;
    return;
}

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