#include <bits/stdc++.h>
using namespace std;
#define endl "\n"
using ll = long long;

int g[20][20]; // 棋盘数组，下标 1~15 有效

signed main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	int cntWhite = 0, cntBlack = 0;
	for (int i = 1; i <= 15; i++)
	{
		for (int j = 1; j <= 15; j++)
		{
			cin >> g[i][j];
			if (g[i][j] == 1)
				cntWhite++;
			else if (g[i][j] == 2)
				cntBlack++;
		}
	}
	if (cntWhite != cntBlack)
	{
		cout << "ERROR!" << endl;
		cout << cntWhite << " " << cntBlack << endl;
		return 0;
	}

	bool whiteWin = false, blackWin = false;
	char whiteDir = '0', blackDir = '0';

	for (int i = 1; i <= 15; i++)
	{
		for (int j = 1; j <= 15; j++)
		{
			if (g[i][j] == 0)
				continue;
			int color = g[i][j];
			if (j + 4 <= 15)
			{
				bool win = true;
				for (int k = 0; k < 5; k++)
				{
					if (g[i][j + k] != color)
					{
						win = false;
						break;
					}
				}
				if (win)
				{
					if (color == 1)
					{
						whiteWin = true;
						whiteDir = 'R';
					}
					else
					{
						blackWin = true;
						blackDir = 'R';
					}
				}
			}
			if (i + 4 <= 15)
			{
				bool win = true;
				for (int k = 0; k < 5; k++)
				{
					if (g[i + k][j] != color)
					{
						win = false;
						break;
					}
				}
				if (win)
				{
					if (color == 1)
					{
						whiteWin = true;
						whiteDir = 'C';
					}
					else
					{
						blackWin = true;
						blackDir = 'C';
					}
				}
			}
			if (i + 4 <= 15 && j + 4 <= 15)
			{
				bool win = true;
				for (int k = 0; k < 5; k++)
				{
					if (g[i + k][j + k] != color)
					{
						win = false;
						break;
					}
				}
				if (win)
				{
					if (color == 1)
					{
						whiteWin = true;
						whiteDir = 'D';
					}
					else
					{
						blackWin = true;
						blackDir = 'D';
					}
				}
			}
			if (i + 4 <= 15 && j - 4 >= 1)
			{
				bool win = true;
				for (int k = 0; k < 5; k++)
				{
					if (g[i + k][j - k] != color)
					{
						win = false;
						break;
					}
				}
				if (win)
				{
					if (color == 1)
					{
						whiteWin = true;
						whiteDir = 'U';
					}
					else
					{
						blackWin = true;
						blackDir = 'U';
					}
				}
			}
		}
	}

	if (whiteWin)
	{
		cout << "White Win,Game Over!" << endl;
		if (whiteDir == 'R')
			cout << "All chess pieces are in the same row." << endl;
		else if (whiteDir == 'C')
			cout << "All chess pieces are in the same column." << endl;
		else if (whiteDir == 'D')
			cout << "All chess pieces are in the same main diagonal." << endl;
		else
			cout << "All chess pieces are in the same Anti-diagonal." << endl;
	}
	else if (blackWin)
	{
		cout << "Black Win,Game Over!" << endl;
		if (blackDir == 'R')
			cout << "All chess pieces are in the same row." << endl;
		else if (blackDir == 'C')
			cout << "All chess pieces are in the same column." << endl;
		else if (blackDir == 'D')
			cout << "All chess pieces are in the same main diagonal." << endl;
		else
			cout << "All chess pieces are in the same Anti-diagonal." << endl;
	}
	else
	{
		cout << "Again!" << endl;
	}

	return 0;
}