#include <bits/stdc++.h>
#define endl "\n"
using ll = long long;
using ull = unsigned long long;
using LL = long long;
using namespace std;
const int inf = 0x3f3f3f3f;
const int N = 1e5+10;

signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr),cout.tie(nullptr);

    int q;
    cin >> q;
    string str;
    cin >> str; 
    while(q--)
    {
        int op;cin >> op;
        if(op == 1)
        {
            string a;
            cin >> a;
            if(str.find(a) != string::npos)
                cout << str.find(a) << endl;
            else
                cout << -1 << endl;
        }
        else if(op == 2)
        {
            string a, b;
            cin >> a >> b;
            if(str.find(a) != string::npos)
            {
                str.replace(str.find(a), a.size(), b);
                cout << str << endl;
            }
            else
            {
                cout << str << endl;
            }
        }
        else
        {
            char c1, c2;
            string s4;
            cin >> c1 >> c2 >> s4;

            string next_str = "";
            for (size_t i = 0; i < str.length(); ++i)
            {
                next_str += str[i];
                if (i + 1 < str.length() && str[i] == c1 && str[i + 1] == c2)
                {
                    next_str += s4;
                }
            }
            str = next_str;
            cout << str << "\n";
        }
        
    }

    return 0;
}