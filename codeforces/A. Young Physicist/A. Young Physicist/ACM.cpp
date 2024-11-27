#include <bits/stdc++.h>
#define endl "\n"
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int N; cin >> N;
    int x[101], y[101], z[101];
    int sum = 0;
    for (int i = 0;i < N;i++)
    {
        cin >> x[i] >> y[i] >> z[i];
        sum += x[i] + y[i] + z[i];
    }
    int sumx = 0, sumy = 0, sumz = 0;
    for (int i = 0;i < N;i++)
    {
        sumx += x[i]; sumy += y[i]; sumz += z[i];
    }
    sum += sumx + sumy + sumz;
    if (sum == 0&&sumx==0)cout << "YES";
    else cout << "NO";
    return 0;
}
