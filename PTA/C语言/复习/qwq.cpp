#include <bits/stdc++.h>
using namespace std;
#define endl "\n"
bool compare(int a, int b) {
    return a > b;
}
int main()
{
    int N; cin >> N;
    while (N--)
    {
        long opponents, totalTime; cin >> opponents >> totalTime;
        vector<long long>  score[500001] = { 0 };
        //vector<long long>  score[500001] = { 0 }, TargetScore[500001] = { 0 };
        long maxScore = 0;
        for (int i = 0; i < opponents; i++)
        {
            cin >> score[i];
            //maxScore = max(score[i], maxScore);
        }
        //TargetScore = score;
        //copy(begin(score), end(score), TargetScore);
        vector<long long> TargetScore = score;
        sort(TargetScore, TargetScore + opponents);
        long n = opponents, m = totalTime;
        long num = 0;
        for (int i = 0; i < n; i++)
        {
            if (m >= TargetScore[i]) {
                m -= TargetScore[i];
                num++;
                maxScore = TargetScore[i];
            }
        }
        long rank = n + 1 - num;
        if (num < n)
        {
            if (score[num] <= maxScore || score[num] - maxScore <= m)
                rank--;
        }
        /*
        if (totalTime > maxScore)cout << 1 << endl;
        else
        {
            for (int i = 0; i < opponents; i++)cout << score[i] << endl;
            for(int i=0;i<opponents;i++)
            {
                if (totalTime > score[i])
                {
                    cout << i+1 << endl;
                    break;
                }
            }
        }
        */
        /*
        for(int i=0;i<n;i++)
        {
            if (totalTime == score[i])
            {
                rank++;
                break;
            }
        }
        */
        cout << rank << endl;
    }
    return 0;
}
