#include <iostream>
using namespace std;

int path[100];
bool vis[100];
int a[100];
void dfs(int u, int n)
{
	if (u == n)
	{
		for (int i = 0; i < n; i++)
		{
			cout << path[i] << " ";
		}
		cout << endl;
	}
	for (int i = 1; i <= n; i++)
	{
		if (!vis[i])
		{
			path[u] = i;
			vis[i] = true;
			dfs(u + 1,n);
			vis[i] = false;
		}
	}
}

int main()
{
	int n;
	cin >> n;
	for (int i = 1; i <= n;i++)
		cin >> a[i];
	for (int i = 1;i <)
}