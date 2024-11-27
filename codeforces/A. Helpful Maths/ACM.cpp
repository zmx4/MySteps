#include <bits/stdc++.h>
#define endl "\n"
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    string a; cin >> a;
    int b[200]={0};
    int j = 0;
    for(int i = 0;i < a.length();i++)
    {
	    if(a[i]>='0'&&a[i]<='9')
	    {
            b[j] = a[i] - '0';
            j++;
	    }
    }
    sort(b, b + j);
    for(int i = 0;i < j;i++)
    {
        cout << b[i];
        if (i != j - 1)cout << "+";
    }
    return 0;
}
