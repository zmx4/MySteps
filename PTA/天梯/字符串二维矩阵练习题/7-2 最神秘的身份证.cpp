#include <bits/stdc++.h>
#define endl "\n"
using ll = long long;
using ull = unsigned long long;
using LL = long long;
using namespace std;
const int inf = 0x3f3f3f3f;
const int N = 1e5+10;
int getnum(char c)
{
    if(c >= '0' && c <= '9')
        return c - '0';
    return -1;
}
char getchar(int num)
{
    if(num >= 0 && num <= 9)
        return '0' + num;
    return '?';
}
int weight[] = {7, 9, 10, 5, 8, 4, 2, 1, 6, 3, 7, 9, 10, 5, 8, 4, 2};
signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr),cout.tie(nullptr);

    string id;
    cin >> id;
    ll sum = 0;
    for(int i = 0; i < id.size(); i++)
    {
        int num = getnum(id[i]);
        sum += num * weight[i];
    }
    sum %= 11;
    char l[] = {'1', '0', 'X', '9', '8', '7', '6', '5', '4', '3', '2'};
    if(l[sum] == id.end()[-1])
    {
        string yyyy = id.substr(6, 4), mm = id.substr(10, 2), dd = id.substr(12, 2);
        string sex = (id[16] - '0') % 2 == 0 ? "F" : "M";
        cout << id << ": " << yyyy << "-" << mm << "-" << dd << " " << sex << "\n";
    }
    else
    {
        cout << id << ": N0\n";
    }
    return 0;
}