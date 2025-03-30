#include <bits/stdc++.h>
using ll = long long;
using ull = unsigned long long;
using namespace std;

signed main()
{
	ios::sync_with_stdio(false);cin.tie(nullptr);
	string s;
	cin>>s;
	s=' '+s;
	int n;cin>>n;
	while(n--)
	{
		/*
		int st,e;cin>>st>>e;
		string p,a;cin>>p>>a;
		int si = p.size();
		for(int i = st;i <= e - si;i++)
		{
			string tmp = s.substr(i,si);
			if(tmp == p)
			{
				s.replace(i,si,a);
				break;
			}
		}
		*/
		int st,e;cin>>st>>e;
		string p,a;cin>>p>>a;
		s.substr(st,e-st+1);
		auto i = s.find(st);
	}
	cout<<s.substr(1)<<endl;

	return 0;
}


/*


AcrosstheGreatWall,wecanreacheverycornerintheworld
5
10 18 ery cor
32 40 , we
1 6 tW all
14 18 rnerr eache
1 1 e r

he,allcornetrrwecaneacheveryGreatWintheworldAcross

*/

