#include<iostream>
using namespace std;
int population(int a)
{
    if(a%2==0)return a/2;
    else return a/2;
}
int main()
{
    int qwe;cin>>qwe;
    while(qwe--)
    {
        int area;cin>>area;
        int a[area][area];
        for(int i = 0;i < area;i++)
        {
            for(int j = 0;j < area;j++)
            {
                cin>>a[i][j];
            }
        }
        int sign = 0;
        for(int i = area - 1;i > (area/2)-1;i--)
        {
            for(int j = 0;j < i;j++)
            {
                cout<<i<<" "<<j<<" "<<endl;
                if(a[i][j]!=0)
                {
                    sign = 1;
                    
                }
            }
        }
        if(sign == 1)cout<<"NO"<<endl;
        else if(sign == 0)cout<<"YES"<<endl;
        //cout<<area/2;
    }
}