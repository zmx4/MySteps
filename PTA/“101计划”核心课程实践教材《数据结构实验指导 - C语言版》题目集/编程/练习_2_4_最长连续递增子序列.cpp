#include <bits/stdc++.h>
#define endl "\n"
#define ll long long
using namespace std;

signed main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr),cout.tie(nullptr);

    int n;
    cin >> n;
    vector<int> nums(n);
    for(int i = 0; i < n; i++)
        cin >> nums[i];
    int cnt = 0,ans = 0,pos = 0;
    for(int i = 1; i < n; i++)
    {
        if(nums[i] > nums[i-1])
        {
            cnt++;
            if(cnt > ans)
            {
                ans = cnt;
                pos = i - ans;
            }
        }
        else
            cnt = 0;
    }
    for(int i = pos; i < pos + ans + 1; i++)
    {
        cout << nums[i];
        if(i < pos + ans) cout << " ";
    }

	return 0;
}