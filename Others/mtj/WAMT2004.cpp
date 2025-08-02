#include <bits/stdc++.h>
#define endl "\n"
using ll = long long;
using ull = unsigned long long;
using LL = long long;
using namespace std;
const int inf = 0x3f3f3f3f;
const int N = 1e5+10;
string make_palindrome(string s)
{
    string second_half = s.substr(0, s.length() / 2);
    reverse(second_half.begin(), second_half.end());
    return s + second_half;
}
signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr), cout.tie(nullptr);
    string n_str;
    cin >> n_str;
    int len = n_str.length();
    int half_len = (len + 1) / 2;
    string first_half = n_str.substr(0, half_len);
    string p = make_palindrome(first_half);
    if (p > n_str)
    {
        // 如果构造的 p 比 n 大，我们需要将前半部分减 1
        int i = first_half.length() - 1;
        while (i >= 0)
        {
            if (first_half[i] > '0')
            {
                first_half[i]--;
                break;
            }
            else
            {
                first_half[i] = '9';
                i--;
            }
        }
        // 如果减 1 后，首位变成 '0' (例如从 "100" 减到 "099")
        // 这意味着结果的位数会减少
        if (first_half[0] == '0' && first_half.length() > 1)
        {
            // 最大的、位数少 1 的回文数就是 n-1 个 '9'
            cout << string(len - 1, '9') << endl;
            return 0;
        }
        // 重新构造回文数
        p = make_palindrome(first_half);
    }

    cout << p << endl;

    return 0;
}