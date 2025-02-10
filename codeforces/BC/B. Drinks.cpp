//
// Created by Tick on 24-11-21.
//
#include<bits/stdc++.h>
using namespace std;
int main()
{
  int n;cin>>n;
  int b = n;
  int sum=0;
  while(n--)
  {
    int a;cin>>a;
    sum+=a;
  }
  printf("%.12f",(double)sum/b);
}