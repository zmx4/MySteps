#include<bits/stdc++.h>
using namespace std;

/*
给你一个长度为n的数组a,现在要你构造一个长度为n的美丽数组b。
我们这样认为：如果一个数组当中的所有元素都有相同的奇偶性，那么这个数组就是美丽的。也就是说，美丽数组中的所有数字都大于零，并且要么全是偶数，要么全是奇数。
要构造数组b，你可以为每个b[i]赋值a[i]或a[i]-a[j]。你可以选择从1到n的任何j。
问你是否有可能构造出来数组b

输入格式:
第一行一个整数t，表示有t个测试样例。
对于每个测试样例，第一行给出一个整数n，表示数组长度。第二行给出n个整数。

输出格式:
对于每个测试样例，输出“YES”或“NO”

输入样例:
在这里给出一组输入。例如：

7
5
2 6 8 4 3
5
1 4 7 6 9
4
2 6 4 10
7
5 29 13 9 10000001 11 3
5
2 1 2 4 2
5
2 4 5 4 3
4
2 5 5 4
输出样例:
在这里给出相应的输出。例如：

No
Yes
Yes
Yes
Yes
No
No


*/
signed main()
{
	int T; cin >> T;
	while (T--)
	{
		int n; cin >> n;
		vector <int> arr(n);
		int j = 0, o = 0;
		int minj = 1000, mino = 1000;
		for (int i = 0; i < n; i++)
		{
			cin >> arr[i];
			if (arr[i] % 2 == 0)
			{
				o++;
				mino = min(mino, arr[i]);
			}
			else
			{
				j++;
				minj = min(minj, arr[i]);
			}
		}
		if (j == 0 || o == 0)
		{
			cout << "Yes" << endl;
		}
		else
		{
			if (mino - minj < 0)cout << "No" << endl;
			else cout << "Yes" << endl;
		}
	}
}