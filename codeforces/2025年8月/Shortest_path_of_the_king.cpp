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
inline void solve()
{
    // char sx, ex;
    // int sy,ey;
    // cin >> sx >> sy >> ex >> ey;
	// int disx = sx - ex;
    // int disy = sy - ey;
	// vector<string> ans;
    // if(disx>0&&disy>0)
    // {
    //     for(int i=0;i<min(disx,disy);i++)
    //     {
    //         ans.pb("LU");
    //     }
    //     disx -= min(disx, disy);
    //     disy -= min(disx, disy);
    //     for(int i=0;i<disx;i++)
    //     {
    //         ans.pb("L");
    //     }
    //     for(int i=0;i<disy;i++)
    //     {
    //         ans.pb("U");
    //     }
    // }
	// else if(disx>0&&disy<0)
    // {
    //     for(int i=0;i<min(disx, -disy);i++)
    //     {
    //         ans.pb("LD");
    //     }
    //     disx -= min(disx, -disy);
    //     disy += min(disx, -disy);
    //     for(int i=0;i<disx;i++)
    //     {
    //         ans.pb("L");
    //     }
    //     for(int i=0;i<-disy;i++)
    //     {
    //         ans.pb("D");
    //     }
    // }
    // else if(disx<0&&disy>0)
    // {
    //     for(int i=0;i<min(-disx, disy);i++)
    //     {
    //         ans.pb("RD");
    //     }
    //     disx += min(-disx, disy);
    //     disy -= min(-disx, disy);
    //     for(int i=0;i<-disx;i++)
    //     {
    //         ans.pb("R");
    //     }
    //     for(int i=0;i<disy;i++)
    //     {
    //         ans.pb("U");
    //     }
    // }
    // else if(disx<0&&disy<0)
    // {
    //     for(int i=0;i<min(-disx, -disy);i++)
    //     {
    //         ans.pb("RU");
            
    //     }
    //     disx += min(-disx, -disy);
    //     disy += min(-disx, -disy);
    //     for(int i=0;i<-disx;i++)
    //     {
    //         ans.pb("R");
    //     }
    //     for(int i=0;i<-disy;i++)
    //     {
    //         ans.pb("D");
    //     }
    // }
    // else if(disx==0&&disy>0)
    // {
    //     for(int i=0;i<disy;i++)
    //     {
    //         ans.pb("U");
    //     }
    // }
	// else if(disx==0&&disy<0)
    // {
    //     for(int i=0;i<-disy;i++)
    //     {
    //         ans.pb("D");
    //     }
    // }
    // else if(disx>0&&disy==0)
    // {
    //     for(int i=0;i<disx;i++)
    //     {
    //         ans.pb("L");
    //     }
    // }
    // else if(disx<0&&disy==0)
    // {
    //     for(int i=0;i<-disx;i++)
    //     {
    //         ans.pb("R");
    //     }
    // }
    // cout << ans.size() << endl;
    // for(auto &i:ans)
    // {
    //     cout << i << endl;
    // }
    string s, t;
    cin >> s >> t;

    // 计算水平和垂直位移
    int dx = t[0] - s[0]; // >0 表示向右(R), <0 表示向左(L)
    int dy = t[1] - s[1]; // >0 表示向上(U), <0 表示向下(D)

    vector<string> ans;

    while (dx != 0 || dy != 0)
    {
        string move = "";
        // 判断水平移动方向
        if (dx > 0)
        {
            move += "R";
            dx--;
        }
        else if (dx < 0)
        {
            move += "L";
            dx++;
        } 
        if (dy > 0)
        {
            move += "U";
            dy--;
        }
        else if (dy < 0)
        {
            move += "D";
            dy++;
        }
        ans.pb(move);
    }

    cout << ans.size() << endl;
    for (const auto &move : ans)
    {
        cout << move << endl;
    }
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