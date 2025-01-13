#include <bits/stdc++.h>
#define endl "\n"
#define ll long long
using namespace std;
bool isPrime(const long long &n)
{
	if (n <= 1)
		return false;
	if (n == 2)
		return true;
	if (n % 2 == 0)
		return false;
	for (long long i = 3; i * i <= n; i += 2)
	{
		if (n % i == 0)
			return false;
	}
	return true;
}

signed main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr), cout.tie(nullptr);

	string n;
	cin >> n;

	try
	{
		long long num_initial = stoll(n);
		if (num_initial > 9)
		{
			string a = "";
			for (int i = n.length() - 2; i >= 0; i--)
			{
				a += n[i];
			}
			n += a;
		}
		long long num = stoll(n);
		if (isPrime(num))
			cout << "prime" << endl;
		else
			cout << "noprime" << endl;
	}
	catch (const out_of_range &)
	{
		cout << "noprime" << endl;
	}
	catch (const invalid_argument &)
	{

		cout << "noprime" << endl;
	}

	return 0;
}