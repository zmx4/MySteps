#include <iostream>
#include <vector>
#include <cstdlib>
#include <functional>
#include <cstring>
#include <algorithm>
#define MAX_SIZE 100050
using namespace std;
class myalg{
	public:
		//求最大公约数
		int GCD1(int a, int b)
		{
			while (b != 0)
			{
				int r = a % b;
				a = b;
				b = r;
			}
			return a;
		}
		// 递归求最大公约数
		int GCD2(int a, int b)
		{
			if (b == 0)
				return a;
			else
				return GCD2(b, a % b);
		}
		// 求最小公倍数
		int lcm(int a, int b)
		{
			return a * b / GCD1(a, b);
		}
};

void insertsort(int a[], int n)
{
	for (int j = 1; j < n;j++)
	{
		int key = a[j];
		int i = j - 1;
		while(i>=0&&a[i]>key)
		{
			a[i + 1] = a[i];
			i--;
		}
		a[i + 1] = key;
	}
}

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

void quicksort(int a[], int l, int r)
{
	if(l<r)
	{
		int i = l;
		int j = r;
		int key = a[l];
		while(i<j)
		{
			while(i<j&&a[j]>=key)
				j--;
			a[i] = a[j];
			while(i<j&&a[i]<=key)
				i++;
			a[j] = a[i];
		}
		a[i] = key;
		quicksort(a, l, i - 1);
		quicksort(a, i + 1, r);
	}
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