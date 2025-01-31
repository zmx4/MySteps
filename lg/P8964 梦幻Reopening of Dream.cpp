#include <bits/stdc++.h>
#define endl "\n"
#define ll long long
using namespace std;

signed main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr),cout.tie(nullptr);

	int T;
	cin >> T;
	int n, m;
	cin >> n >> m;
	vector<string> a(2*n);
	int cnt = 0;
	for (int i = 0; i < m;i++)
	{
		string temp;
		cin >> temp;
		a[cnt] = "freopen(\"" + temp + ".in\",\"r\",stdin);";
		cnt++;
		a[cnt] = "freopen(\"" + temp + ".out\",\"w\",stdout);";
		cnt++;
	}
	
	while(n--)
	{
		int st = 1;
		for (int i = 0;i < 2*m;i++)
		{
			//string blank;
			//getline(cin, blank);
			int tempst = st;
			string temp;
			cin >> temp;
			if(temp == a[i])
			{
				continue;
			}
			else if ((temp.substr(0, 10) == "//freopen(") && (temp.substr(temp.length() - 2) == ");"))
			{
				tempst = 3;
			}
			else
			{
				tempst = 2;
			}
			st = max(st, tempst);
		}
		if(st == 1)
		{
			cout << "PION2202 RP++." << endl;
		}
		else if(st == 2)
		{
			cout << "Good luck and have fun." << endl;
		}
		else if (st == 3)
		{
			cout << "Wrong file operation takes you to your ancestors along with your 3 years' efforts on OI." << endl;
		}
	}

	return 0;
}


// 函数用于判断某个freopen语句是否为注释形式
bool is_commented_freopen(const string &s)
{
	if (s.size() < 12)
		return false; // "//freopen(" -> 最少需要12个字符
	if (s.substr(0, 10) == "//freopen(" && s.substr(s.size() - 2) == ");")
	{
		return true;
	}
	return false;
}
/*
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int T;
	cin >> T;

	while (T--)
	{
		int n, m;
		cin >> n >> m;

		// 读取m个题目名称
		vector<string> titles(m);
		for (int i = 0; i < m; ++i)
		{
			cin >> titles[i];
		}

		// 为了处理后续的空行，读取一个换行符
		cin.ignore(); // 忽略当前行的剩余部分

		// 定义输出字符串
		const string NORMAL = "PION2202 RP++.";
		const string ANCESTOR = "Wrong file operation takes you to your ancestors along with your 3 years' efforts on OI.";
		const string FUN = "Good luck and have fun.";

		// 遍历n位选手
		for (int player = 0; player < n; ++player)
		{
			// 读取一个空行
			string blank;
			getline(cin, blank);

			// 读取2*m行freopen语句
			vector<string> operations(2 * m);
			for (int i = 0; i < 2 * m; ++i)
			{
				getline(cin, operations[i]);
			}

			// 初始化分类标志
			bool has_commented = false;
			bool has_other = false;

			// 检查每个freopen语句
			for (int i = 0; i < 2 * m; ++i)
			{
				string expected;
				// 根据奇偶性决定是输入还是输出语句
				if (i % 2 == 0)
				{
					expected = "freopen(\"" + titles[i / 2] + ".in\",\"r\",stdin);";
				}
				else
				{
					expected = "freopen(\"" + titles[i / 2] + ".out\",\"w\",stdout);";
				}

				if (operations[i] == expected)
				{
					// 正常的freopen语句
					continue;
				}
				else
				{
					// 检查是否为注释形式
					if (is_commented_freopen(operations[i]))
					{
						has_commented = true;
					}
					else
					{
						has_other = true;
					}
				}
			}

			// 根据分类优先级输出结果
			if (has_commented)
			{
				cout << "Wrong file operation takes you to your ancestors along with your 3 years' efforts on OI.\n";
			}
			else if (has_other)
			{
				cout << "Good luck and have fun.\n";
			}
			else
			{
				cout << "PION2202 RP++.\n";
			}
		}
	}

	return 0;
}
*/