#include <bits/stdc++.h>
using namespace std;

void drawTotem(vector<string> &grid, int x, int y, int size)
{
	if (size == 1)
	{
		grid[x][y] = '/';
		grid[x][y + 1] = '\\';
		grid[x + 1][y - 1] = '/';
		grid[x + 1][y] = '_';
		grid[x + 1][y + 1] = '_';
		grid[x + 1][y + 2] = '\\';
		return;
	}
	int half = size / 2;
	drawTotem(grid, x, y, half);
	drawTotem(grid, x + half, y - half, half);
	drawTotem(grid, x + half, y + half, half);
}

int main()
{
	int n;
	cin >> n;
	int height = 1 << n;
	int width = 1 << (n + 1);
	vector<string> grid(height, string(width, ' '));
	int startX = 0;
	int startY = width / 2 - 1;
	drawTotem(grid, startX, startY, height / 2);
	for (auto &line : grid)
	{
		size_t pos = line.find_last_not_of(' ');
		if (pos != string::npos)
		{
			cout << line.substr(0, pos + 1) << endl;
		}
		else
		{
			cout << endl;
		}
	}
	return 0;
}