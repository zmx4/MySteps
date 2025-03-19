#include <iostream>
#include<string>
using namespace std;
int main()
{
  // 请在此输入您的代码
  int n;cin>>n;
  while(n--)
  {
    string a;cin>>a;
    //cout<<a[a.length()]<<endl;
    if(a[a.length()-1]=='9')a.push_back('0');
    else a[a.length()-1]+=1;
    cout<<a<<endl;
  }

  return 0;
}