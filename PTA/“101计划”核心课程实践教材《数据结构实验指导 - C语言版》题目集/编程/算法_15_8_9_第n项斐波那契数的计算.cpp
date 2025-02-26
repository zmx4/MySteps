#include <bits/stdc++.h>
#define endl "\n"
#define ll long long
using namespace std;
ll Fibonacci_generalItem(int n)
{
    const double sqrt5 = std::sqrt(5);
    const double phi = (1 + sqrt5) / 2;
    const double psi = (1 - sqrt5) / 2;
    return std::round((std::pow(phi, n) - std::pow(psi, n)) / sqrt5);
}

ll fib_recursive(int n, vector<ll>& memo) {
    if(memo[n] != -1) return memo[n];
    memo[n] = fib_recursive(n-1, memo) + fib_recursive(n-2, memo);
    return memo[n];
}

ll fib_iterative(int n) {
    if(n < 2) return 1;
    ll a = 1, b = 1;
    for(int i = 2; i <= n; i++){
        ll c = a + b;
        a = b;
        b = c;
    }
    return b;
}

signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int n;
    cin >> n;
    
    // 方法1：递归（带备忘录）
    vector<ll> memo(n+1, -1);
    memo[0] = 1;
    if(n >= 1) memo[1] = 1;
    ll ans_rec = fib_recursive(n, memo);
    
    // 方法2：循环
    ll ans_iter = fib_iterative(n);
    
    // 输出其中一种结果（答案应相同）
    cout << ans_iter << "\n";
    
    return 0;
}