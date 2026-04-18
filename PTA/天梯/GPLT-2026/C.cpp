#include<bits/stdc++.h>
using namespace std;
signed main()
{
	int n,m;cin >> n >> m;
	cout << m - n << endl;
	if(m-n<=0)
	{
		cout << "hai sheng ma?" << endl;
	}
	else if(m - n > 250)
	{
		cout << "jiu ting tu ran de..."<<endl;
	}
	else
	{
		cout << "nin tai cong ming le!" << endl;
	}
	return 0;
}
