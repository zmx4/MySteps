#include <iostream>
#include <set>
using namespace std;

int main()
{
	string s;
	cin >> s;
	set<char> cnt;
	for (auto c : s)
		cnt.insert(c);
	cout << cnt.size();
}
// 64 位输出请用 printf("%lld")