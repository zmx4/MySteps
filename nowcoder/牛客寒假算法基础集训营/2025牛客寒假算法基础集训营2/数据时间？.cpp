#include <bits/stdc++.h>
#define endl "\n"
using namespace std;

int main()
{
	int n, h, m;
	cin >> n >> h >> m;
	unordered_set<string> a1, a2, a3;
	while (n--)
	{
		ios::sync_with_stdio(false);
		cin.tie(nullptr);
		int YYYY, MM, DD, hh, mm, ss;
		string user_id;
		// scanf(" %d-%d-%d %d:%d:%d", &YYYY, &MM, &DD, &hh, &mm, &ss);
		cin >> user_id >> YYYY;
		cin.ignore(1);
		cin >> MM;
		cin.ignore(1);
		cin >> DD;
		cin.ignore(1);
		cin >> hh;
		cin.ignore(1);
		cin >> mm;
		cin.ignore(1);
		cin >> ss;
		if (YYYY == h && MM == m)
		{
			if (
				(hh == 7) ||
				(hh == 8) ||
				(hh == 9 && mm == 0 && ss == 0) ||
				(hh == 18) ||
				(hh == 19) ||
				(hh == 20 && mm == 0 && ss == 0))
			{
				a1.insert(user_id);
			}

			if (
				(hh == 11) ||
				(hh == 12) ||
				(hh == 13 && mm == 0 && ss == 0))
			{
				a2.insert(user_id);
			}

			if (
				(hh == 22) ||
				(hh == 23) ||
				(hh == 0) ||
				(hh == 1 && mm == 0 && ss == 0))
			{
				a3.insert(user_id);
			}
		}
	}

	cout << a1.size() << " " << a2.size() << " " << a3.size() << endl;
	return 0;
}