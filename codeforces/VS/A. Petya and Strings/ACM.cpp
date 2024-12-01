#include <bits/stdc++.h>
#define endl "\n"
using namespace std;

string DtoX(const string &str)
{
    string res;
    for (int i = 0; i < str.length(); ++i) {
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

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    string a, b; cin >> a >> b;
    a = DtoX(a);b=DtoX(b);

    bool sign = false;

    for(int i = 0;i < a.length();i++)
    {
	    if(a[i]<b[i])
	    {
            cout << "-1" << endl;
            sign = true;
            break;
	    }
        else if(a[i] > b[i])
        {
            cout << "1" << endl;
            sign = true;
            break;
        }
    }
    if (sign == false)cout << "0";
    return 0;
}
