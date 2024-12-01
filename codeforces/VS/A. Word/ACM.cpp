#include <bits/stdc++.h>
#define endl "\n"
using namespace std;

string DtoX(const string& str)
{
    string res;
    for (int i = 0; i < str.length(); ++i) 
    {
        if (str[i] >= 'A' && str[i] <= 'Z') 
        { 
            res += tolower(str[i]); 
        }
        else 
        {
            res += str[i]; 
        }
    }
    return res;
}

string XtoD(const string& str)
{
    string res;
    for (int i = 0; i < str.length(); ++i) 
    {
        if (str[i] >= 'a' && str[i] <= 'z') 
        { 
            res += toupper((str[i]));
        }
        else 
        {
            res += str[i];
        }
    }
    return res;
}

bool judgeD(const string& str)
{
    int D = 0, X = 0;
    for (int i = 0; i < str.length(); ++i)
    {
        if (str[i] >= 'a' && str[i] <= 'z')X++;
        if (str[i] >= 'A' && str[i] <= 'Z')D++;
    }
    return D > X;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    string a; cin >> a;
    if (judgeD(a))a = XtoD(a);
    else a = DtoX(a);
    cout << a;
    return 0;
}
