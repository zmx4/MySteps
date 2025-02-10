//24-11-27 Tick
#include <bits/stdc++.h>
#define endl "\n"
using namespace std;

bool judgeUpper(string s)
{
  for (int i = s.length() - 1; i >= 0; i--)
  {
    if (s[i] >= 'a' && s[i] <= 'z')
    {
      return false;
    }
  }
  return true;
}

signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int flaga = 0,flagb = 0;
    string s;cin>>s;

    if(s[0]>='a' && s[0]<='z')
    {
        string s1 = s.substr(1,s.length()-1);
        if(judgeUpper(s1))flaga=1;
    }
	  else if(s[0]>='A' && s[0]<='Z')
    {
      if(judgeUpper(s))flagb=1;
    }
    if(flaga==1)
    {
      s[0]=toupper(s[0]);
      for(int i = 1; i < s.length(); i++)
      {
        s[i] = tolower(s[i]);
      }
    }
    else if(flagb==1)
    {
      for(int i = 0; i < s.length(); i++)
      {
        s[i] = tolower(s[i]);
      }
    }
    cout<<s;
    return 0;
}
