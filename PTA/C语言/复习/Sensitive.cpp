#include <bits/stdc++.h>
using namespace std;
int n, m;
string s, forbiddenWords[110];
int main()
{
	int qwe;cin>>qwe;
    cin.ignore();
    while (qwe--)
    {
        cin >> n;
	cin.ignore();
	for (int i = 0; i < n; i++)getline(cin, forbiddenWords[i]);
	
	cin >> m;
	if (m == 0) cout << 0 << endl << "YLSZJJFJQ";
	else
	{
		cin.ignore();
		int cnt = 0;
		getline(cin, s);
		for (int i = 0; i < n; i++)
		{
			while (s.find(forbiddenWords[i]) != s.npos)
			{
				int pos = s.find(forbiddenWords[i]);
				cnt++;
				s.erase(pos, forbiddenWords[i].length());
				s.insert(pos, "-_-");
			}
		}
		if (cnt >= m) cout << cnt << endl << "YLSZJJFJQ";
		else
		{
			// 找出违禁词的位置然后替换
			while (s.find("-_-") != -1)
			{
				int t = s.find("-_-");
				s.erase(t, 3);
				s.insert(t, "<censored>");
			}
			cout << s;
		}
	}
    }
    
	return 0;
}