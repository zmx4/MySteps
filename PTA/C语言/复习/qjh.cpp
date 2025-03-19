#include<bits/stdc++.h>
using namespace std;
int main()
{
    int a[1000],b[1000];
    for(int i = 1;i<5;i++)
    {
        cin>>a[i];
    }
    //sort(a.begin(),a.end());
    for(int i = 1;i<5;i++)
    {
        if(a[i]>b[i-1])b[i]=a[i];
        else b[i] = b[i-1];
    }
    for(int i = 1;i<5;i++)
    {
        cout<<b[i]<<endl;
    }

}