#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int x, y;
    int a[6][6] = { 0 };
    for(int i = 1;i <= 5;i++)
    {
	    for(int j = 1;j <=5;j++)
	    {
            cin >> a[i][j];
            if(a[i][j]==1)
            {
                x = i;
                y = j;
            }
	    }
    }

    int sx = abs(x - 3), sy = abs(y - 3);
    cout << sx + sy;
    return 0;
}
