//
// Created by Tick on 24-11-20.
//
#include <bits/stdc++.h>
using namespace std;
int main()
    {
      string s;cin>>s;
      string a = "hello";int j = 0;
      for(int i=0;i<s.length();i++)
        {
            if(s[i]==a[j])
              {
                  j++;
              }
        }
    if(j==5)cout<<"YES";
    else cout<<"NO";
    return 0;
    }


