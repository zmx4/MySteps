#include <bits/stdc++.h>
#define endl '\n'
#define lowbit(x) (x) & (-x)
using namespace std;

typedef double db;
typedef long long ll;
typedef __int128 III;
const db eqs = 1e-6;
const int inf = 1e9;
void ll_cmax(ll &a, ll b) { a = a > b ? a : b; }
void ll_cmin(ll &a, ll b) { a = a < b ? a : b; }
void int_cmax(int &a, int b) { a = a > b ? a : b; }
void int_cmin(int &a, int b) { a = a < b ? a : b; }
bool db_eq(db a, db b) { return fabs(a - b) < eqs; }
bool number(char ch) { return ch >= '0' && ch <= '9'; }
bool lowerchar(char ch) { return ch >= 'a' && ch <= 'z'; }
int sqlong(int n)
{
    int sq = sqrt(n) + 1;
    return min(sq, n);
}

const int MAXN = 200000 + 5;
int T, a[MAXN];
ll n, k;

ll quick_power(ll a, ll n)
{
    if (n == 0)
        return 1;
    if (n == 1)
        return a;
    ll sum = quick_power(a * a, n / 2);
    if (n % 2 == 1)
        sum *= a;
    return sum;
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> T;
    while (T--)
    {
        cin >> n >> k;
        int cnt = 0;
        ll sum = 1;
        while (sum < k)
        {
            sum *= 2;
            ++cnt;
        }
        if (n - 1 < cnt)
        {
            cout << -1 << endl;
            continue;
        }
        //		cout<<"ok\n";
        int q = n - 1, l = 1, r = n;
        for (int i = 1; i <= n; i++)
        {
        cout<<k<<" "<<cnt<<" "<<q<<endl;
            if (cnt <= q - 1)
            {
                a[l++] = i;
            }
            else
            {
                a[r--] = i;
                k -= quick_power(2, q - 1);
                sum = 1;
                cnt = 0;
                while (sum < k)
                {
                    sum *= 2;
                    ++cnt;
                }
            }
            q--;
        }
        cout << k << " " << cnt << " " << q << endl;
        for (int i = 1; i <= n; i++)
            cout << a[i] << " ";
        cout << endl;
    }
    return 0;
}
// by Matrix_Power
/*

思考过程：

a1 a2 a3 a4

a1+a1+a1+a1+a2+a2+a2+a3+a3+a4=4a1+3a2+2a3+a4

-------------------------

a4 a3 a2 a1

a4+a3+a2+a1+a3+a2+a1+a2+a1+a1=4a1+3a2+2a3+a4

-------------------------

a3 a2 a1 a4

a3+a2+a1+a1+a2+a1+a1+a1+a1+a4=6a1+2a2+a3+a4

-------------------------

a1 a2 a3 a4
a1 a3 a4 a2
a1 a4 a3 a2
a2 a3 a4 a1
a2 a4 a3 a1
a3 a4 a2 a1
a4 a3 a2 a1

(n-1)n/2+1?No
*/

/*
k=2,cnt=1,q=2
1 2 3 4  0
1 2 4 3  1
1 3 4 2  2
1 4 3 2  3
2 3 4 1  3
2 4 3 1  4
3 4 2 1  5
4 3 2 1  6
*/

/*
k=2,q=1,cnt=1
1 2 3
1 3 2
2 3 1
3 2 1
*/
