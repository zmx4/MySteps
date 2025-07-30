#include <bits/stdc++.h>
#define endl "\n"
using ll = long long;
using ull = unsigned long long;
// using namespace std;
const int inf = 0x3f3f3f3f;
struct DSU {
    std::vector<int> p, r;
    DSU(int n) : p(n + 1), r(n + 1, 0) {
        std::iota(p.begin(), p.end(), 0);
    }
	int find(int x) {
		return p[x] == x ? x : p[x] = find(p[x]);
	}
	bool unite(int a, int b) {
		a = find(a);
		b = find(b);
		if (a == b)
			return false;
		if (r[a] < r[b])
            std::swap(a, b);
        p[b] = a;
		if (r[a] == r[b])
			r[a]++;
		return true;
	}
};
signed main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr), std::cout.tie(nullptr);
    int n;
    std::cin >> n;

    return 0;
}