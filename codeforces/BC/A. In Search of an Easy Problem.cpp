//
// Created by Tick on 24-11-20.
//
#include <bits/stdc++.h>
using namespace std;
int main()
{
  int n;cin>>n;
  int sign = 0;
  while(n--){
    int a;cin>>a;
    if(a==1)sign = 1;
  }
  if(sign == 1)cout<<"HARD"<<endl;
  else cout<<"EASY"<<endl;
}