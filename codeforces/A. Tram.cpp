//
// Created by Tick on 24-11-20.
//
#include <bits/stdc++.h>
using namespace std;
int main()
{
  int t;cin>>t;
  int passenger = 0;int maxn = 0;
  while(t--) {
    int n;cin>>n;
    int f;cin>>f;
    passenger +=f;passenger-=n;
    maxn = max(passenger,maxn);
  }
  cout<<maxn;
}