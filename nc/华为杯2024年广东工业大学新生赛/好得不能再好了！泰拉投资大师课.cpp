#include <bits/stdc++.h>
using namespace std;

const int MOD = 1e9 + 7;
const int MAXN = 2e5 + 5;

long long qkm(long long a, long long b)
{
    long long re = 1;
    long long t = a;
    while (b > 0)
    {
        if (b & 1)re = (re * t) % MOD;
        t = (t * t) % MOD;
        b /= 2;
    }
    return re;
}

vector<long long> fact(MAXN, 1), inv_fact(MAXN, 1);

void preprocess()
{
    for (int i = 2; i < MAXN; ++i)
    {
        fact[i] = fact[i - 1] * i % MOD;
        inv_fact[i] = qkm(fact[i], MOD - 2);
    }
}

long long comb(int n, int k)
{
    if (k > n || k < 0)
        return 0;
    return fact[n] * inv_fact[k] % MOD * inv_fact[n - k] % MOD;
}

long long solve(int n, int p, int q)
{
    long long win_prob = qkm(q, MOD - 2);
    long long lose_prob = (q - p + MOD) % MOD * win_prob % MOD;
    win_prob = p * win_prob % MOD;

    long long total_prob = 0;
    for (int i = 0; i < n; ++i)
    {
        total_prob += comb(n - 1 + i, i) * qkm(win_prob, n) % MOD * qkm(lose_prob, i) % MOD;
        total_prob %= MOD;
    }

    return total_prob;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);

    preprocess();

    int T;
    cin >> T;
    while (T--)
    {
        int n, p, q;
        cin >> n >> p >> q;
        cout << solve(n, p, q) << endl;
    }

    return 0;
}