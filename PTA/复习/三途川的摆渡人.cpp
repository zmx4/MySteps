#include<iostream>
using namespace std;


int main()
{
    int a;cin>>a;
    string b;cin>>b;
    int sum = 0;
    for(int i = 0;i < a;i++)
    {
        if(b[i]=='0')sum++;
    }
    cout<<sum;
}