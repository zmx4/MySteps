//
// Created by Tick on 24-11-22.
//
#include<bits/stdc++.h>
using namespace std;
typedef unsigned long long ull;
const int N = 1000010,base = 131;
int main(){
  string s;cin>>s;
  string t='0'+s;
  ull hash[s.length()+1];
  hash[0]=0;
  for(int i=1;i<=s.length();i++){
    hash[i]=hash[i-1]*base + t[i] - 'a' + 1;
  }
  for(int i=1;i<=s.length();i++){
    printf("%llu\n",hash[i]);
  }
}