//
// Created by Tick on 24-11-21.
//
#include<bits/stdc++.h>
#define int long long int
using namespace std;
signed main()
{
  int n;cin>>n;
  int flag = -1;
  int a = 1;
  int sum = 0;
  /*
  for(int i=1;i<=n;i++) {
    sum+=flag*i;
    flag *= -1;
    cout<<sum<<" "<<i<<endl;
  }
  */
  if (n%2 == 0)sum=n/2;
  else sum=(n+1)/2*(-1);
  cout<<sum<<endl;
}