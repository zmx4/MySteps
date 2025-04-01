#include<iostream>
using namespace std;

int path[100];
bool vis[100];
int n;
void dfs(int u)
{
	if(u==n)
	{
		for (int i = 0; i < n;i++)
		{
			cout << path[i] << " ";
		}
		cout << endl;
	}
	for (int i = 1; i <= n;i++)
	{
		if(!vis[i])
		{
			path[u] = i;
			vis[i] = true;
			dfs(u + 1);
			vis[i] = false;
		}
	}
}

int main()
{
	
	cin >> n;
	dfs(0);
}