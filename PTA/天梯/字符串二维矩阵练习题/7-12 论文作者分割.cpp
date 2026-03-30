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

    string str;
    getline(cin, str);
    string current = "";
    vector<string> vec;

    for (int i = 0; i <= str.size(); ++i)
    {
        if (i == str.size() || str[i] == ',')
        {
            int start = 0;
            int end = current.size() - 1;
            while (start < current.size() && isblank(current[start]))
            {
                start++;
            }
            while (end >= 0 && isblank(current[end]))
            {
                end--;
            }
            if (start <= end)
            {
                vec.push_back(current.substr(start, end - start + 1));
            }
            current.clear();
        }
        else
        {
            current += str[i];
        }
    }

    for (const auto &name : vec)
    {
        cout << name << endl;
    }
    return 0;
}