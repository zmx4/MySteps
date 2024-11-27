#include <bits/stdc++.h>
#define endl "\n"
using namespace std;

string DtoX(const string& str) {
    string res;
    for (int i = 0; i < str.length(); ++i) {
        if (str[i] >= 'A' && str[i] <= 'Z') { // 检查是否为大写字母
            res += tolower(str[i]); // 转换为小写并添加到结果字符串
        }
        else {
            res += str[i]; // 如果不是大写字母，则直接添加到结果字符串
        }
    }
    return res;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    string a; cin >> a;
    a = DtoX(a);
    string b = "";
    for(int i = 0;i < a.length();i++)
    {
	    if(a[i]!='a'&& a[i] != 'e' && a[i] != 'i' && a[i] != 'o' && a[i] != 'u' && a[i] != 'y')
	    {
            b += '.';
            b += a[i];
	    }
    }
    cout << b;
    return 0;
}
