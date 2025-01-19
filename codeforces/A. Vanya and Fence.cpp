//
// Created by Tick on 24-11-20.
//
#include <bits/stdc++.h>
using namespace std;
int main()
{
  int n,maxHighth;cin>>n>>maxHighth;
  int cnt = 0;
  //cout<<n;
  while(n--)
    {
        int a;cin>>a;
        if(a<=maxHighth)cnt++;
        else cnt+=2;
    }
    cout<<cnt;
}