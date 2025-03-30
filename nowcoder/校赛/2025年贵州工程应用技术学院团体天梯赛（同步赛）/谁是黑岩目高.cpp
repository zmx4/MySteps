#include<bits/stdc++.h>
using namespace std;
using ll = long long;

void solve()
{
	string s;
	getline(cin,s);
	//for(auto &c:s)if(isupper(c))tolower(c);
	string t = "shinto mekkaku";
	auto check=[&](string s){
        string ss="";
        for(int i=0;i<s.size();i++){
            if(s[i]==' '){
                ss+=s[i];
            }else ss+=tolower(s[i]);
        }
        if(ss.find(t)!=string::npos){
            return true;
        }else return false; 
	};
	if(check(s))cout<<"Medaka Kuroiwa"<<endl;
	else cout<<"Bonnjinn"<<endl;
}



signed main()
{
	int t;cin>>t;
	cin.ignore();
	while(t--)
	{
		solve();
	}
}