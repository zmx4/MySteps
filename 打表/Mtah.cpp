#include <bits/stdc++.h>
#define endl "\n"
using ll = long long;
using ull = unsigned long long;
using LL = long long;
using namespace std;
const int inf = 0x3f3f3f3f;
const int N = 1e5+10;
std::vector<int> generatePrimesSieve(int l, int r)
{
    // 构造大小为 r+1 的布尔数组，初始值全部设为 true
    std::vector<bool> isPrime(r + 1, true);

    // 0 和 1 不是质数
    if (r >= 0)
        isPrime[0] = false;
    if (r >= 1)
        isPrime[1] = false;

    // 遍历到 sqrt(r)，因为超过 sqrt(r) 的 i 没有必要再筛
    int limit = std::sqrt(r);
    for (int i = 2; i <= limit; i++)
    {
        if (isPrime[i])
        {
            // 从 i*i 开始标记所有 i 的倍数为非质数
            for (int j = i * i; j <= r; j += i)
            {
                isPrime[j] = false;
            }
        }
    }

    // 收集大于等于 l 的质数（注意：质数起始从 2 开始）
    std::vector<int> primes;
    for (int i = std::max(l, 2); i <= r; i++)
    {
        if (isPrime[i])
        {
            primes.push_back(i);
        }
    }
    return primes;
}
signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr),cout.tie(nullptr);

    // cin.exceptions(cin.failbit);
    vector<int> primes = generatePrimesSieve(1, 100);
    for(auto p: primes) cout << p << " ";
    cout << endl;
    cout<<primes.size()<<endl;







    return 0;
}