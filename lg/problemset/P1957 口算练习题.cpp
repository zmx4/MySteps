#include <bits/stdc++.h>
#define endl "\n"
#define ll long long
using namespace std;

signed main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr),cout.tie(nullptr);

	int i;
	cin >> i;
	cin.ignore();

	char curOp;
	for (int idx = 0; idx < i; idx++)
	{
		string line;
		getline(cin, line);
		if (line.empty())
		{
			idx--;
			continue;
		}
		istringstream iss(line);
		string token;
		int a, b;
		iss >> token;
		if (token == "a" || token == "b" || token == "c")
		{
			curOp = token[0];
			iss >> a >> b;
		}
		else
		{
			a = stoi(token);
			iss >> b;
		}
		int res;
		char opChar;
		if (curOp == 'a')
		{
			res = a + b;
			opChar = '+';
		}
		else if (curOp == 'b')
		{
			res = a - b;
			opChar = '-';
		}
		else if (curOp == 'c')
		{
			res = a * b;
			opChar = '*';
		}
		string equation = to_string(a) + string(1, opChar) + to_string(b) + "=" + to_string(res);
		cout << equation << "\n"
			 << equation.size() << "\n";
	}

	return 0;

	return 0;
}