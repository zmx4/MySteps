#include <iostream>
#include <string>

using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    string s;
    if (!(cin >> s))
        return 0;

    int q;
    cin >> q;

    while (q--)
    {
        int l, r;
        string s1, s2;
        cin >> l >> r >> s1 >> s2;
        l--;
        r--;
        int len = r - l + 1;

        string cut_str = s.substr(l, len);
        s.erase(l, len);

        string target = s1 + s2;
        size_t pos = s.find(target);
        if (pos != string::npos)
        {
            s.insert(pos + s1.length(), cut_str);
        }
        else
        {
            s += cut_str;
        }
    }
    cout << s << endl;

    return 0;
}