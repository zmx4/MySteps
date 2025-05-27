#include<stdio.h>
const int N = 100010;
int a[100010];
int used[100010];
int n;
void dfs(int u)
{
	if(u == n)
	{
		for(int i = 0; i < n; i++)
		{
			//if(i && i != n) printf(" ");
			printf("%d", a[i]);
		}
		printf("\n");
		return;
	}
	for(int i = 1; i <= n; i++)
	{
		if(!used[i])
		{
			a[u] = i;
			used[i] = 1;
			dfs(u + 1);
			used[i] = 0;
		}
	}
}
int main()
{
	scanf("%d", &n);
	dfs(0);
}