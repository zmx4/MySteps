
#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n, minScore; cin >> n >> minScore;
    int cnt = 0;
    int a[101] = { 0 };
    for(int i = 0;i < n;i++)
    {
        cin >> a[i];
    }
    int now = minScore;
    int end;
    for (int i = 0; i < n; i++)
    {
        if(minScore>0)
        {
            if (a[i] >= a[i + 1] && a[i] != 0)
            {
                cnt++;
                minScore--;
                end = a[i];
            }
        }
        else if ( a[i] == end)
        {
            cnt++;
            //cout << a[i];
            //cout << cnt << endl;
        }
    }
    

    cout << cnt;
}

