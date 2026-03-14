#include<bits/stdc++.h>
using namespace std;
#define int long long

signed main()
{
	int h ,h1 , h2;
	cin >> h >> h1 >> h2;
	cout << h << endl;
	if(h < h1)
	{
		cout << "Bu Kan" ;
	}
	else if (h < h2)
	{
		cout << "Zhe Gua Bao Shu Ma";
	}
	else
	{
		cout << "Chi Gua";
	}
}
