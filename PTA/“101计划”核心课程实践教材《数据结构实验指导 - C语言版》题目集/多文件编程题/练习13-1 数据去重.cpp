#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;
    vector<string> filename(n);
    for (auto &str : filename)
        cin >> str;
    string output_filename;
    cin >> output_filename;

    set<ll> data;
    for (auto &str : filename)
    {
        ifstream in(str);
        ll num;
        while (in >> num) // 直接读取整数，每行一个
        {
            data.insert(num);
        }
        in.close();
    }

    ofstream out(output_filename);
    // 使用反向迭代器实现严格递减序输出
    bool first = true;
    for (auto it = data.rbegin(); it != data.rend(); ++it)
    {
        if (!first)
            out << "\n";
        out << *it;
        first = false;
    }
    out.close();

    return 0;
}