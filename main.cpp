#include <iostream>
#include <vector>
#include <cstdlib>
#include <functional>
#include <cstring>
#include <algorithm>
#define MAX_SIZE 100050
using namespace std;
char *StrStr(const char *txt, const char *pat)
{
	if(pat[0]=='\0')return NULL;
	int n = strlen(txt);
	int m = strlen(pat);
	for(int i = 0;i<=n-m;i++)
	{
		int j = 0;
		while(j<m&&txt[i+j]==pat[j])
			j++;
		if(j==m)
			return (char*)txt+i;
	}
	return NULL;
}

bool isPrime(int n)
{
	if(n<=1)return false;
	if(n==2)return true;
	if(n%2==0)return false;
	for(int i = 3;i*i<=n;i+=2)
	{
		if(n%i==0)
			return false;
	}
	return true;
}


signed main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	//int a[MAX_SIZE];
	//memset(a, 0, sizeof(a));
	int n;
	cin >> n;
	vector<int> a(n,0);
	for (int i = 0; i < n;i++)
	{
		cin >> a[i];
	}
	//lambda
	sort(a.begin(), a.end(), [](int a, int b){ return a > b; });
	for (int i = 0; i < n;i++)
	{
		cout << a[i]<<" ";
	}
	cout << endl;
	sort(a.begin(), a.end(), greater());
	for (int i = 0; i < n; i++)
	{
		cout << a[i]<<" ";
	}
	cout << endl;
	sort(a.begin(), a.end());
	for (int i = 0; i < n; i++)
	{
		cout << a[i]<<" ";
	}
	cout << endl;
}