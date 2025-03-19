#include <iostream>
#include <string>
using namespace std;

int main()
{
	string a;
	getline(cin, a);
	cin.ignore();
	char x;
	cin >> x;
	int cnt = 0;
	for (char ch : a)
	{
		if (ch == x)
		{
			cnt++;
		}
	}
	cout << cnt;
}