#include <bits/stdc++.h>
using namespace std;

int getPos(int a, int b, int time)
{
    int timea = 2 * abs(b - a);
    int timeb = time % timea;
    if (timeb < abs(b - a)) return a + timeb;
    else return b - (timeb - abs(b - a));
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int n, m;cin >> n >> m;

    vector<pair<int, int>> cars(n);
    for (int i = 0; i < n; i++)
    {
        cin >> cars[i].first >> cars[i].second;
    }

    for (int i = 0; i < m; i++)
    {
        int x, y, t;
        cin >> x >> y >> t;
        int cnt = 0;
        for (int j = 0; j < n; j++)
        {
            int a = cars[j].first;
            int b = cars[j].second;
            int pos = getPos(a, b, t);
            if (x <=pos && pos <= y) 
            {
                cnt++;
            }
        }
        cout << cnt << endl;
    }

    return 0;
}