#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n,k,m;cin>>n>>k>>m;
    int FinalScore[N+1]={0};int tempScore[N+1]={0};
    for(int i = 0;i < n;i++)
    {
        int maxScore = 0,minScore = 100;
        int score;
        int sum = 0;
        for(int j = 0;j < k;j++)
        {
            cin>>score;
            maxScore=max(maxScore,score);minScore=min(minScore,score);
            sum+=score;
        }
        sum -= maxScore;sum -= minScore;
        FinalScore[i]=sum / (k - 2);
    }
    sort(FinalScore,FinalScore+n);
    for(int i = k;i > 0;i--)
    {
        cout<<FinalScore[i]<<" "[i != k-3];
    }
}