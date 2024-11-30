#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n,k,m;cin>>n>>k>>m;
    double FinalScore[n+1]={0};double tempScore[n+1]={0};
    for(int i = 0;i < n;i++)
    {
        double maxScore = 0,minScore = 100;
        double score;
        double sum = 0;
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
    for(int i = n-m;i < n;i++)
    {
        //cout<<FinalScore[i]<<" "[i != k-3];
        printf("%.3f",FinalScore[i]);
        if(i != n - 1)printf(" ");
    }
}