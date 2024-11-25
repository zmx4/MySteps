//
// Created by Tick on 24-11-21.
//
#include<bits/stdc++.h>
using namespace std;
int main()
{
  int n;cin>>n;
  int sum=1;
  string s;cin>>s;
  n--;
  while(n--)
  {
    string sa;cin>>sa;
    if(s!=sa)sum+=1;
    s=sa;
  }
  cout<<sum<<endl;
}