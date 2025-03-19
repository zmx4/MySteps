#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    int n, m;
    cin >> n >> m;
    vector<vector<char>> grid(n + 1, vector<char>(m + 1));
    vector<vector<int>> heights(n + 1, vector<int>(m + 1, 0));

    for (int i = 1; i <= n; i++) 
    {
        for (int j = 1; j <= m; j++) 
        {
            cin >> grid[i][j];
            if (grid[i][j] == '.') 
            {
                heights[i][j] = heights[i - 1][j] + 1;
            }
        }
    }

    int maxArea = 0;
    int x1 = 1, y1 = 1, x2 = 1, y2 = 1;

    for (int i = 1; i <= n; i++) 
    {
        for (int j = 1; j <= m; j++) 
        {
            if (grid[i][j] == '*') continue;
            int minHeight = heights[i][j];
            for (int k = j; k >= 1 && grid[i][k] == '.'; k--) 
            {
                minHeight = min(minHeight, heights[i][k]);
                int area = minHeight * (j - k + 1);
                if (area > maxArea) 
                {
                    maxArea = area;
                    x1 = i - minHeight + 1;
                    y1 = k;
                    x2 = i;
                    y2 = j;
                }
            }
        }
    }

    cout << x1 << " " << y1 << " " << x2 << " " << y2 << endl;

    return 0;
}