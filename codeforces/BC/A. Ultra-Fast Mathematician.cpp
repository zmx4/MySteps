#include<bits/stdc++.h>
using namespace std;
int main()
{
  string a,b;cin>>a>>b;
  string c = "";
  for(int i=0;i<a.length();i++)
  {
    if(a[i]==b[i])c.push_back('0');
    else if(a[i]!=b[i])c.push_back('1');
  }
  cout<<c;
}