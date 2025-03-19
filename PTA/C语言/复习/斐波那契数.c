#include <iostream>
#include <string.h>
using namespace std;
int main()

{
    int fa=7,fb=11;
    int n;
    cin>>n;
    long long int a[n];
    a[0]=fa;a[1]=fb;
    long c;
    for(int i=2;i<=n;i++)
    {
        a[i]=a[i-1]+a[i-2];
        //c+=a[i];
    }
    for(int i=0;i<n;i++)
    {
        if(a[i]%3==0)cout<<"yes ";
        else cout<<"no ";
    }
}