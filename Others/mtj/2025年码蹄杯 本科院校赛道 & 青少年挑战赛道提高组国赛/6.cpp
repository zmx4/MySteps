#include <bits/stdc++.h>
#define endl '\n'
#define int long long
using ll = long long;using ull = unsigned long long;using LL = long long;using namespace std;
const int inf = 0x3f3f3f3f;
const int N = 1e6+10;
int trie[N][26];
int num[N];
int pos = 1;
int ans = 0;
int mod = 998244353;
void insert(char str[])
{
	int p = 0;
	for(int i = 0;str[i];i++)
	{
		int n = str[i]-'a';
		if(trie[p][n]==0)
		{
			trie[p][n]=pos++;
		}
		p = trie[p][n];
		ans+=num[p];
		ans %= mod;
		num[p]++;
	}
}
char str[N];
signed main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr), cout.tie(nullptr);
	ll stl = 0;
	int n;cin>>n;
	while(n--)
	{
		cin>>str;
		insert(str);
		stl+=strlen(str);
	}
	cout<<((ans*2)%mod+stl)%mod<<endl;
	return 0;
}
