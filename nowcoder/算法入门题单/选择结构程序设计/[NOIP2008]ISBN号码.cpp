#include <bits/stdc++.h>
#define endl "\n"
#define ll long long
using namespace std;
string formatNumber(int number, int width)
{
	stringstream ss;
	ss << setw(width) << setfill('0') << number;
	return ss.str();
}
signed main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr),cout.tie(nullptr);

	int s1, s2, s3;
	char keya;
	scanf("%d-%d-%d-%c", &s1, &s2, &s3, &keya);
	int key = keya - '0';
	if(keya=='X')
		key = 10;
	string Num = formatNumber(s1, 1) + formatNumber(s2, 3) + formatNumber(s3, 5);
	long sum = 0;
	for (int i = 0; i < 9;i++)
	{
		sum += (Num[i] - '0') * (i + 1);
	}
	// cout << num << endl;
	if (sum % 11 == key)
		cout << "Right" << endl;
	else
	{
		if (sum % 11 == 10)
			printf("%d-%03d-%05d-%c", s1, s2, s3, 'X');
		else
		{
			string str = to_string(s1);
			str += '-';
			str += to_string(s2);
			str += '-';
			str += to_string(s3);
			str += '-';
			str += to_string(sum % 11);
			cout << str << endl;
		}
		}

	return 0;
}