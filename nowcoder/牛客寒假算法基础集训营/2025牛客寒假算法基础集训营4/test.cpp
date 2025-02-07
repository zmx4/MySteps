#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const ll MOD = 1000000007;

// Fast modular exponentiation
ll modexp(ll base, ll exp, ll mod = MOD)
{
	ll result = 1;
	base %= mod;
	while (exp > 0)
	{
		if (exp & 1)
			result = (result * base) % mod;
		base = (base * base) % mod;
		exp >>= 1;
	}
	return result;
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int T;
	cin >> T;
	while (T--)
	{
		int n;
		cin >> n;
		string s;
		cin >> s;

		// Count total number of '?' in the string.
		ll totalQ = 0;
		for (char c : s)
		{
			if (c == '?')
				totalQ++;
		}

		// Special case: when string length is 1.
		if (n == 1)
		{
			// Only one character: flipping it always yields a balanced string
			// (since there are no adjacent characters), so val(s)=1.
			// And there are 2^(# of '?') completions.
			cout << modexp(2, totalQ) % MOD << "\n";
			continue;
		}

		// For n >= 2, note that a binary string is balanced if and only if its
		// first and last characters are equal.
		// For a complete string s (with no '?'):
		//   - If s[0] == s[n-1], then for any i with 2 <= i <= n-1,
		//     flipping s[i] will leave the first and last unchanged and balanced.
		//     Thus, contribution from inner positions is n-2.
		//   - Flipping the first position (i = 1) or the last (i = n)
		//     will change that bit. They yield balanced strings if and only if
		//     after flip, the first and last bits are different from the original,
		//     i.e., s[0] and s[n-1] become different, which happens exactly when s[0] != s[n-1] originally.
		//     Hence, each of the two boundary positions contributes 1 if s[0] != s[n-1].
		// Overall, val(s) = (if s[0] == s[n-1] then n-2 else 2).

		// Now, in our incomplete string s with '?' characters, only s[0] and s[n-1]
		// affect the condition deciding the value. The remaining positions (the inner ones, including '?')
		// do not affect the decision; they only multiply the count by a factor of 2^(# of '?' in inner positions).

		// Let’s compute, for positions 0 and n-1, the count of assignments that result in
		// equal bits and the ones that result in unequal bits.

		ll equal_count = 0, unequal_count = 0;
		// Both positions 0 and n-1 are considered.
		if (s[0] == '?' && s[n - 1] == '?')
		{
			// Possibilities: (0,0), (1,1) -> equal and (0,1), (1,0) -> unequal.
			equal_count = 2;
			unequal_count = 2;
		}
		else if (s[0] == '?' && s[n - 1] != '?')
		{
			// s[n-1] is fixed. For s[0], we have:
			// If we choose the same as s[n-1] then equal, if different then unequal.
			equal_count = 1;
			unequal_count = 1;
		}
		else if (s[0] != '?' && s[n - 1] == '?')
		{
			// Analogous to above.
			equal_count = 1;
			unequal_count = 1;
		}
		else
		{ // Both fixed.
			if (s[0] == s[n - 1])
			{
				equal_count = 1;
				unequal_count = 0;
			}
			else
			{
				equal_count = 0;
				unequal_count = 1;
			}
		}

		// Count of '?' among positions 0 and n-1.
		int boundaryQ = 0;
		if (s[0] == '?')
			boundaryQ++;
		if (s[n - 1] == '?')
			boundaryQ++;

		ll rem = totalQ - boundaryQ; // '?' count in inner positions.

		// For a complete string determined by first and last positions:
		// if they are equal, contribution is n-2; if they are unequal, contribution is 2.
		ll weight = (equal_count * (n - 2) + unequal_count * 2) % MOD;

		// All inner '?' have 2^(rem) completions.
		ll ans = (weight * modexp(2, rem)) % MOD;

		cout << ans % MOD << "\n";
	}
	return 0;
}