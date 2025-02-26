#include <bits/stdc++.h>
#define endl "\n"
#define ll long long
using namespace std;

signed main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr),cout.tie(nullptr);

    map<int, double, greater<int>> poly; 
    int n;
    cin >> n; 
    
    for (int i = 0; i < n; i++) {
        double coef;
        int exp;
        cin >> coef >> exp;
        poly[exp] = coef;
    }
    
    cin >> n;
    
    for (int i = 0; i < n; i++) {
        double coef;
        int exp;
        cin >> coef >> exp;
        poly[exp] += coef; 
    }
    
    bool hasOutput = false;
    for (const auto& term : poly) {
        if (abs(term.second) > 1e-8) { // 避免浮点数精度问题
            cout << fixed << setprecision(2) << term.second << " " << term.first << endl;
            hasOutput = true;
        }
    }
    
    return 0;
}