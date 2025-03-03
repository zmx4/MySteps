#include <bits/stdc++.h>
#define endl "\n"
#define ll long long
using namespace std;

string s1 = "qwertyuiop", s2 = "asdfghjkl;", s3 = "zxcvbnm,./";


signed main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr),cout.tie(nullptr);

    char c;
    cin >> c;
    string s;
    cin >> s;
    if(c == 'R')
    {
        for(int i = 0; i < s.size(); i++)
        {
            if(s1.find(s[i]) != string::npos)
            {
                cout << s1[s1.find(s[i]) - 1];
            }
            else if(s2.find(s[i]) != string::npos)
            {
                cout << s2[s2.find(s[i]) - 1];
            }
            else
            {
                cout << s3[s3.find(s[i]) - 1];
            }
        }
    }
    else
    {
        for(int i = 0; i < s.size(); i++)
        {
            if(s1.find(s[i]) != string::npos)
            {
                cout << s1[s1.find(s[i]) + 1];
            }
            else if(s2.find(s[i]) != string::npos)
            {
                cout << s2[s2.find(s[i]) + 1];
            }
            else
            {
                cout << s3[s3.find(s[i]) + 1];
            }
        }
    }

	return 0;
}