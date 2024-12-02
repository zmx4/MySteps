//24-12-2 Tick
#include <bits/stdc++.h>
#define endl "\n"
using namespace std;

signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);cout.tie(nullptr);

    int n;cin>>n;
    string s[1024];
    string a=" /\\",b="/__\\";
    s[1]=a,s[2]=b;
    for(int i = 2;i <= n;i++)
    {
		for(int j = pow(2,i-1)+1;j <= pow(2,i);j++)
        {
			int temp = j-pow(2,i-1);
        	s[j]=s[temp];//s[temp]="";
        }
    	for(int j = pow(2,i-1)+1;j <= pow(2,i);j++)
    	{
    		if (j <= (pow(2,i-1))*1.5)
    		{
    			int k = i - 2;
    			while (k--)s[j].push_back(' ');
    		}
    		s[j]+=s[j];
    	}
    	/*
    	for (int j = 1;j <= pow(2,i-1);j++)
    	{
			for (int k = 2;k <= i;k++)s[j].insert(0,"  ");
    	}
    	*/

    }
	for (int i = 1; i <= pow(2,n); i++)cout<<s[i]<<endl;
    return 0;
}
/*
	   /\
	  /__\
	 /\  /\
	/__\/__\
   /\      /\
  /__\    /__\
 /\  /\  /\  /\
/__\/__\/__\/__\
*/
/*
	   /\
	  /__\
	 /\  /\
	/__\/__\
   /\      /\
  /__\    /__\
 /\  /\  /\  /\
/__\/__\/__\/__\
*/