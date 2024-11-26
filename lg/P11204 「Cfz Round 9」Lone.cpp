#include<bits/stdc++.h>
#define int long long int
using namespace std;
signed main(){
  ios::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  int t;cin>>t;
  while(t--)
  {
    /*
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
    */
    int n,m;
    cin>>n>>m;
    bool f=1;
    int s1=m%n,s2=n-m%n;
    int len1=m/n+1,len2=m/n;
    if(s1==0){
      cout<<"Yes\n";
    }
    else{
      if(s1>1){
        if(len2+len1<=len1){
          f=0;
        }
      }
      if(s2>1){
        if(len2+len2<=len1){
          f=0;
        }
      }
      if(!f){
        cout<<"No\n";
      }
      else{
        cout<<"Yes\n";
      }
    }
  }
  return 0;
}