#include<iostream>
#include <vector>
using namespace std;
int main()
{
    int n;cin>>n;
    int a[n][n]={0};
    for(int i = 0;i < n;i++)
    {
        for(int j = 0;j < n;j++)
        {
            cin>>a[i][j];
        }
    }
    //int max = -100,maxpos = 0,min = 100,minpos = 0;
    int sign = 0;
    for(int i = 0;i < n;i++)
    {
        int lie = 0;
        sign = 0;
        for(int j = 0;j < n;j++)
        {
            if(a[i][j]>=a[i][lie])lie = j;
            //sign = 1;
        }
    
        for(int j = 0;j < n;j++)
        {
            if(a[i][lie]>a[j][lie])
            {
                sign = 1;
                break;
            }
        }

        if(sign == 0)
        {
            cout<<i<<" "<<lie;
            break;
        }
    }
    if(sign == 1)cout<<"NONE";
}