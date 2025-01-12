#include <bits/stdc++.h>
#define endl "\n"
#define ll long long
using namespace std;

signed main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr),cout.tie(nullptr);

	int ax, ay, az;
	cin >> ax >> ay >> az;
	int a = sqrt(ax * ay / az), b = sqrt(ax * az / ay), c = sqrt(ay * az / ax);


	cout<<4*(a+b+c)<<endl;

	return 0;
}