#include<bits/stdc++.h>
#define int long long int
using namespace std;
signed main(){
  ios::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  int t;cin>>t;
  while(t--){
    int n,m;cin>>n>>m;
    if(m%n==0){
      cout<<"YES"<<endl;
      continue;
    }
    if(m/n==1&&m%n<n-1){
      cout<<"NO"<<endl;
      continue;
    }else{
      cout<<"YES"<<endl;
      continue;
    }
  }
}