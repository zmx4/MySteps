#include<bits/stdc++.h>
#define int long long
using namespace std;
using ll = long long;
using ull = unsigned long long;
const int MAXN = 55;
int g[MAXN][MAXN];
int n,m,h;
int best = -1,bx = 60,by = 60,ans;
int dx[]={0,0,1,-1},dy[]={1,-1,0,0};
bool ava[MAXN][MAXN];
int search(int x,int y)
{
	int sum = 0;
	for(int i = x+1;i < n;i++)
	{
		if(g[i][y]>h)break;
		else if(g[i][y]<0)sum++;
	}
	for(int i = x-1;i >= 0;i--)
	{
		if(g[i][y]>h)break;
		else if(g[i][y]<0)sum++;
	}
	for(int i = y+1;i < m;i++)
	{
		if(g[x][i]>h)break;
		else if(g[x][i]<0)sum++;
	}
	for(int i = y+1;i >= 0;i--)
	{
		if(g[x][i]>h)break;
		else if(g[x][i]<0)sum++;
	}
	return sum;
}

void solve()
{
	cin>>n>>m>>h;
	for(int i = 0;i < n;i++)
		for(int j = 0;j < m;j++)
		{
			int x;cin>>x;
			if(x<0)g[i][j]=-1;
			else if(x<h)g[i][j]=0;
			else
			{
				g[i][j]=x;
				//cout<<i<<" "<<j<<endl;
			}
			if(g[i][j]!=0)ava[i][j]=false;
		}
	for(int i = 0;i < n;i++)
		for(int j = 0;j < m;j++)
		{
			int tmp = search(i,j);
			if(tmp >= 3)
			{
				ans++;
				if(bx>i)
				{
					bx = i,by = j;
				}
				else if(bx == i&&by>j)
				{
					by = j;
				}
			}
		}
	cout<<ans<<endl<<bx<<" "<<by<<endl;
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int N, M, H;
	cin >> N >> M >> H;
	vector<vector<int>> grid(N, vector<int>(M));
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < M; j++)
		{
			cin >> grid[i][j];
		}
	}

	// 结果：优秀观赏位置数量，以及最佳（看到烟花最多）位置（行、列）
	int excellentCount = 0;
	int bestVisible = -1;
	int bestX = 0, bestY = 0;

	// 对每个候选位置（空格子，即值为 0），向四个方向扫描
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < M; j++)
		{
			if (grid[i][j] != 0)
				continue; // 只有空格子才是候选位置

			int visible = 0;
			// 向上扫描
			for (int r = i - 1; r >= 0; r--)
			{
				int val = grid[r][j];
				if (val > 0 && val >= H)
					break; // 阻挡
				if (val < 0)
					visible++; // 燃放烟花
			}
			// 向下扫描
			for (int r = i + 1; r < N; r++)
			{
				int val = grid[r][j];
				if (val > 0 && val >= H)
					break;
				if (val < 0)
					visible++;
			}
			// 向左扫描
			for (int c = j - 1; c >= 0; c--)
			{
				int val = grid[i][c];
				if (val > 0 && val >= H)
					break;
				if (val < 0)
					visible++;
			}
			for (int c = j + 1; c < M; c++)
			{
				int val = grid[i][c];
				if (val > 0 && val >= H)
					break;
				if (val < 0)
					visible++;
			}
			if (visible >= 3)
			{
				excellentCount++;
				if (visible > bestVisible || (visible == bestVisible && (i < bestX || (i == bestX && j < bestY))))
				{
					bestVisible = visible;
					bestX = i;
					bestY = j;
				}
			}
		}
	}

	cout << excellentCount << "\n";
	cout << bestX << " " << bestY << "\n";

	return 0;
}