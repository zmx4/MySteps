#include<bits/stdc++.h>
using namespace std;
signed main()
{
	int q;string str;
	cin >> q;
	cin.ignore();
	getline(cin,str);
	while(q--)
	{
		int op;cin >> op;
		if(op == 1)
		{
			vector<int>pos;
			string tar;
			cin >> tar;
			for(int i = 0;i < str.size() - tar.size() + 1;++i)
			{
				if(str.substr(i,tar.size()) == tar)
				{
					pos.push_back(i);
				}
			}
			if(pos.size()==0)
			{
				cout << -1 << endl;
			}
			else
			{
				bool flag = 0;
				for(auto i : pos)
				{
					if(flag)cout << " ";
					cout << i;
					flag = 1;
				}
				cout << endl;
			}
		}
		if(op == 2)
		{
			int p;string s;
			cin >> p >> s;
			str.insert(p,s);
			cout << str << endl;
		}
		if(op == 3)
		{
			int l,r;
			cin >> l >> r;
			reverse(str.begin()+l,str.begin()+r+1);
			cout << str << endl;
		}
	}
	
	return 0;
}
