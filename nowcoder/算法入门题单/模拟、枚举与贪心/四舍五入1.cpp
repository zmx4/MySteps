#include <iostream>
using namespace std;

int n, t;
string s;

int main()
{
	cin >> n >> t >> s;
	int pos = s.find('.');
	if (pos == -1)
	{
		cout << s << endl;
		return 0;
	}
	for (int i = pos + 1; i < s.size(); i++)
	{
		if (s[i] >= '5')
		{
			s.erase(i--);
			t--;
			while (s[i] == '4' && t--)
				s.erase(i--);
			if (s[i] == '.')
			{
				s.erase(i--);
				while (s[i] == '9')
					s[i--] = '0';
				if (i == -1)
					cout << 1;
				else
					s[i]++;
			}
			else
				s[i]++;
		}
	}
	cout << s << endl;
}