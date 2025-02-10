#include <bits/stdc++.h>
#define endl "\n"
#define int long long int
using namespace std;

signed main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);cout.tie(nullptr);

	int x1, x2, x3, x4;
	cin>>x1>>x2>>x3>>x4;

	int max = std::max(x1, std::max(x2, std::max(x3, x4)));//a+b+c
	int min = std::min(x1, std::min(x2, std::min(x3, x4)));//a+b
	int mid = x1 + x2 + x3 + x4 - max - min;//a+b+2c
	int arr[4] = {x1, x2, x3, x4};
	sort(arr, arr + 4);
	//        3a+3b+3c    a+b+c  a+b
	//

	/*
	max = a+b+c
	min = a+b
	=> c = max - min
	=> b = min - a
	=> a = min - b
	*/

	int c = max - min;
	int temp = mid - (2 * c);
	int b = arr[1]-c;
	int a = arr[2] - c;
	cout << a << " " << b << " " << c;
	return 0;
}