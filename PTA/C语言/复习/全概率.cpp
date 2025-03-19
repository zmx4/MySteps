#include<iostream>
using namespace std;
int main()
{
    int N;cin>>N;
    int a,b,sum;
    while(N--)
    {
        cin>>a>>b;
        sum+=a*b;
    }
    cout<<sum;
}
