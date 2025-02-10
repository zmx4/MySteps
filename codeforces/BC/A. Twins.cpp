//
// Created by Tick on 24-11-21.
//
#include<bits/stdc++.h>
using namespace std;
int main()
{
  int n;cin>>n;
  int a[110]={0};
  int suma=0;
  int sumb=0;
  for(int i=0;i<n;i++){
    cin>>a[i];
    suma+=a[i];
  }
  sort(a,a+n);
  int ans = 0;
  for(int i=n-1 ;i>=0;i--){
    suma-=a[i];
    sumb+=a[i];
    ans++;
    if(suma<sumb)break;
  }
  cout<<ans<<endl;
}