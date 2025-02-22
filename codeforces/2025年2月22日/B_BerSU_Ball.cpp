//// filepath: /d:/Dev/MySteps/codeforces/2025年2月22日/B_BerSU_Ball.cpp
#include <bits/stdc++.h>
#define endl "\n"
#define ll long long
using namespace std;

signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr), cout.tie(nullptr);

    int b;
    cin >> b;
    vector<int> boys;
    for (int i = 0; i < b; i++)
    {
        int x;
        cin >> x;
        boys.push_back(x);
    }
    int g;
    cin >> g;
    vector<int> girls;
    for (int i = 0; i < g; i++)
    {
        int x;
        cin >> x;
        girls.push_back(x);
    }
    sort(boys.begin(), boys.end());
    sort(girls.begin(), girls.end());
    int ans = 0;
    bool usedBoy[101] = { false };
    bool usedGirl[101] = { false };
    for (int i = 0; i < b; i++)
    {
        for (int j = 0; j < g; j++)
        {
            if (abs(boys[i] - girls[j]) <= 1 && !usedBoy[i] && !usedGirl[j])
            {
                ans++;
                usedBoy[i] = true;
                usedGirl[j] = true;
                break;
            }
        }
    }
    cout << ans << endl;
    return 0;
}